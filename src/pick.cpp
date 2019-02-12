#include <ros/ros.h>
#include <actionlib/server/simple_action_server.h>
#include <armadillo2_bgu/OperationAction.h>
#include <armadillo2_bgu/SimplePickAction.h>
#include <armadillo2_bgu/SimplePlaceAction.h>
#include <actionlib/client/simple_action_client.h>
#include <armadillo2_bgu/SimpleTargetAction.h>

#include <cv_bridge/cv_bridge.h>
#include <opencv2/opencv.hpp>

//not needed with dan's code
#include <geometry_msgs/PoseStamped.h>
#include <geometry_msgs/PointStamped.h>

#include <tf/transform_listener.h>
#include <tf/transform_datatypes.h>

typedef actionlib::SimpleActionServer<armadillo2_bgu::OperationAction> Server;
typedef actionlib::SimpleActionClient<armadillo2_bgu::OperationAction> Client;

typedef actionlib::SimpleActionClient<armadillo2_bgu::SimplePickAction> Pick_client;
typedef actionlib::SimpleActionClient<armadillo2_bgu::SimpleTargetAction> Target_client_t;

typedef actionlib::SimpleActionClient<armadillo2_bgu::SimplePlaceAction> Place_client;

float x;
float y;
float z;
float w;
float h;
bool gotXYZ = false;
std::string camFrameID = "kinect2_depth_optical_frame";
bool moved = false;

void move();
void transform_goal(geometry_msgs::PointStamped& transformed_goal);

void move(){
    Target_client_t target_client("move", true);
    target_client.waitForServer();

    armadillo2_bgu::SimpleTargetGoal goal_target;
    std::cout<<"camFrameID: "<<camFrameID<<std::endl;
    goal_target.frame_id = camFrameID;
    goal_target.obj_name = "target";
    goal_target.x = x;
    goal_target.y = y;
    goal_target.z = z;

    target_client.sendGoal(goal_target);
    target_client.waitForResult();
}

//with Dan's vision
void observeDoneCB(const actionlib::SimpleClientGoalState& state,
        const armadillo2_bgu::OperationResultConstPtr& res){
    std::string x1 = ((res->res).substr((res->res).find('x')+1,(res->res).find('y')));
    x = std::stof (x1);

    std::string y1 = (res->res).substr((res->res).find('y')+1,(res->res).find('z'));
    y = std::stof (y1);

    std::string z1 = (res->res).substr((res->res).find('z')+1,(res->res).find('w'));
    z = std::stof (z1);

    std::string w1 = ((res->res).substr((res->res).find('w')+1,(res->res).find('h')));
    w = std::stof (w1);

    std::string h1 = ((res->res).substr((res->res).find('h')+1,(res->res).find('\0')));
    h = std::stof (w1);

    std::cout<<"[Pick]: (x,y,z): "<<x<<","<<y<<","<<z<<std::endl;

    w = 0.022;
    h = 0.1;
}

//simple vision
void poseCB(const geometry_msgs::PoseStamped::ConstPtr& msg) {
    x = msg->pose.position.x;
    y = msg->pose.position.y;
    z = msg->pose.position.z;
   //x = -0.112948;
   //y = 0.0866848;
   //z = 0.754;

    w = 0.022;
    h = 0.1;
    camFrameID = msg->header.frame_id;
    gotXYZ =true;
}

void pick_cb(const armadillo2_bgu::OperationGoalConstPtr& goal, Server* as){
    ROS_INFO("Starting pick sequence");

  // with Dan's vision
//    armadillo2_bgu::OperationGoal sendGoal;
//    Client client("observe", true);
//    client.waitForServer();
//    client.sendGoal(sendGoal, &observeDoneCB);

    //client.sendGoal(sendGoal);
//    if(!client.waitForResult()){
//        ROS_INFO("Vision failed");
//    }
//    else {


//Simple vision
          while (!gotXYZ)
             ros::Duration(0.5).sleep();

    geometry_msgs::PointStamped transformed_goal;
    transform_goal(transformed_goal);
    std::cout<<"after transform x: " << transformed_goal.point.x<<std::endl;


        ROS_INFO("[pick]: Calling arm_pick");
        Pick_client pick_client("arm_pick", true);
        pick_client.waitForServer();

        //creating the pick goal.
        armadillo2_bgu::SimplePickGoal pick_goal;
        pick_goal.frame_id = transformed_goal.header.frame_id;
        pick_goal.obj_name = "target";
        pick_goal.x = transformed_goal.point.x;
        pick_goal.y = transformed_goal.point.y;
        pick_goal.z = transformed_goal.point.z;
        pick_goal.h = h;
        pick_goal.w = w;

        //send the goal
        actionlib::SimpleClientGoalState pick_status = pick_client.sendGoalAndWait(pick_goal);


        if (!(pick_status == actionlib::SimpleClientGoalState::SUCCEEDED)) {
            //what to do when pick fail
            ROS_INFO("Failed to pick");
            if (!moved) {
                move();
                moved = true;
                pick_cb(goal,as);
            }
            else
                as->setAborted();
        }
        else
            as->setSucceeded();
        ROS_INFO("Done Picking");
//    }
}

/**
 * place the object.
 *
 * @param goal
 * @param as
 */
void place_cb(const armadillo2_bgu::OperationGoalConstPtr& goal, Server* as){
    Place_client place_client("simple_place", true);
    place_client.waitForServer();

    while (!gotXYZ)
        ros::Duration(0.5).sleep();

    geometry_msgs::PointStamped transformed_goal;
    transform_goal(transformed_goal);
    std::cout<<"after transform x: " << transformed_goal.point.x<<std::endl;

    armadillo2_bgu::SimplePlaceGoal place_goal;
    place_goal.frame_id = transformed_goal.header.frame_id;
    place_goal.obj_name = "target";
    place_goal.x = transformed_goal.point.x;
    place_goal.y = transformed_goal.point.y;
    place_goal.z = transformed_goal.point.z;
    place_goal.h = h;
    place_goal.w = w;

    //send the goal
    actionlib::SimpleClientGoalState place_status = place_client.sendGoalAndWait(place_goal);

    if (!(place_status == actionlib::SimpleClientGoalState::SUCCEEDED)) {
        //what to do when pick fail
        ROS_INFO("Failed to place");
        as->setAborted();
    }
    else
        as->setSucceeded();
    ROS_INFO("Done Picking");
}

void transform_goal(geometry_msgs::PointStamped& transformed_goal){

    // get original goal point
    geometry_msgs::PointStamped origin_goal;
    origin_goal.header.frame_id = camFrameID;

    std::cout<<"goal->x:"<<x<<"\ngoal->y"<<y<<"\ngoal->z:"<<z<<std::endl;
    origin_goal.point.x = x;
    origin_goal.point.y = y;
    origin_goal.point.z = z+0.035;
    ROS_INFO("[arm_server]: goal is set ");

    // transfer original goal in relation to base footprint

    try
    {
        tf::TransformListener transformer;
        ROS_INFO("[arm_server]: trying to transform 1 ");
        std::cout<<"origin_goal.header.frame_id:"<<origin_goal.header.frame_id<<std::endl;
        ros::Duration(2).sleep();
        transformer.waitForTransform("/base_footprint",origin_goal.header.frame_id,ros::Time(),ros::Duration(15));
        ROS_INFO("[arm_server]: trying to transform 2 ");
        transformer.transformPoint("/base_footprint", origin_goal, transformed_goal);
        ROS_INFO("[arm_server]: Transformed");
    }
    catch (tf::TransformException ex)
    {
        ROS_INFO("Exception!");
        ROS_ERROR("%s",ex.what());
    }
}




int main(int argc, char** argv)
{
  ros::init(argc, argv, "arm");
  std::cout<<"Pick online"<<std::endl;
  ros::NodeHandle n;

  //for simple vision
  ros::Subscriber sub = n.subscribe("object_pose", 100, poseCB);

  Server pick_server(n, "bgu/pick", boost::bind(&pick_cb, _1, &pick_server), false);
  Server place_server(n,"bgu/place",boost::bind(&place_cb,_1,&place_server),false);

  pick_server.start();
  place_server.start();

  ros::AsyncSpinner spinner(2);
  spinner.start();
  ros::waitForShutdown();

  return 0;
}
