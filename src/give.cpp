#include <ros/ros.h>
#include <actionlib/server/simple_action_server.h>
#include <actionlib/client/simple_action_client.h>
#include <armadillo2_bgu/OperationAction.h>

#include <moveit/planning_scene_interface/planning_scene_interface.h>
#include <moveit/move_group_interface/move_group_interface.h>

void arm_position(std::string name);

typedef actionlib::SimpleActionServer<armadillo2_bgu::OperationAction> Server;
typedef actionlib::SimpleActionClient<armadillo2_bgu::OperationAction> Client;

bool cobra = false;

void arm_position(std::string name){
    ROS_INFO("[give]: Setting arm position");
    moveit::planning_interface::MoveGroupInterface group("arm");
    group.setPlanningTime(10.0);
    group.setNumPlanningAttempts(50);
    group.setPlannerId("RRTConnectkConfigDefault");
    group.setPoseReferenceFrame("base_footprint");

    group.setStartStateToCurrentState();
    group.setNamedTarget(name);
    moveit::planning_interface::MoveGroupInterface::Plan startPosPlan;
    if(group.plan(startPosPlan)){
        group.execute(startPosPlan);
        cobra = true;
    }
    
}

void doneSTT(const actionlib::SimpleClientGoalState& state,
            const armadillo2_bgu::OperationResultConstPtr& result)
{
    ROS_INFO("[give]: in doneSTT");
    std::cout<<"result->res:"<<result->res<<std::endl;
    if(result->res == "bgu_open") {
        Client open_client("open", true);
        open_client.waitForServer();
        armadillo2_bgu::OperationGoal open_goal;
        open_client.sendGoal(open_goal);
    }
}

void feedbackSTT(const armadillo2_bgu::OperationFeedbackConstPtr& feedback)
{
    ROS_INFO("[Give]: in feedbackSTTCB");
    //ROS_INFO("Got Feedback of length %lu", feedback->feed.);
}

void activeSTT()
{
}

void activeCB()
{
    ROS_INFO("[Give]: Goal just went active");
    Client STT_client("text_check",true);
    STT_client.waitForServer();
    
    armadillo2_bgu::OperationGoal STT_goal;
    STT_client.sendGoal(STT_goal,&doneSTT,&activeSTT,&feedbackSTT);
    STT_client.waitForResult(ros::Duration(30.0));
}
//Check if "open" in string

void feedbackCB(const armadillo2_bgu::OperationFeedbackConstPtr& feedback)
{
    ROS_INFO("[Give]: in feedbackCB");
    //ROS_INFO("Got Feedback of length %lu", feedback->feed.);
}
void doneCB(const actionlib::SimpleClientGoalState& state,
            const armadillo2_bgu::OperationResultConstPtr& result)
{

}

//TODO write comments like you should.
void execute(const armadillo2_bgu::OperationGoalConstPtr& goal, Server* as) 
{
	armadillo2_bgu::OperationResult result_;
    ROS_INFO("IN give: Starting give squence");

    arm_position("cobra_center");
    //Extend server
    if(cobra){
        Client extend_client("bgu_extend", true);
        extend_client.waitForServer();
        armadillo2_bgu::OperationGoal extend_goal;
        extend_client.sendGoalAndWait(extend_goal);

        //TTS server
        Client TTS_client("describe_wuc",true);
        TTS_client.waitForServer();

        armadillo2_bgu::OperationGoal TTS_goal;
        TTS_goal.data = "Tell me when to open the gripper";
        TTS_client.sendGoal(TTS_goal);
        activeCB();
    }


/**
    if(true) {
        as->setSucceeded(result_);
    }
    else{ 
        as->setAborted();
    }
**/
}

int main(int argc, char** argv)
{
  ros::init(argc, argv, "Give");
  std::cout<<"give ready"<<std::endl;
  ros::NodeHandle n;
  Server server(n, "bgu_give", boost::bind(&execute, _1, &server), false);
  server.start();
  ros::spin();
  return 0;
}
