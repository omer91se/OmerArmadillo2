#include <ros/ros.h>
#include <move_base_msgs/MoveBaseAction.h>
#include <actionlib/client/simple_action_client.h>
#include <actionlib/server/simple_action_server.h>
#include <armadillo2_bgu/OperationAction.h>


typedef actionlib::SimpleActionClient<move_base_msgs::MoveBaseAction> MoveBaseClient;
typedef actionlib::SimpleActionServer<armadillo2_bgu::OperationAction> Server;

MoveBaseClient *ac_ptr = nullptr;



void move_to_object_cb(const armadillo2_bgu::OperationGoalConstPtr& goal, Server* as){
    move_base_msgs::MoveBaseGoal move_goal;

    //we'll send a goal to the robot to move 1 meter forward
    move_goal.target_pose.header.frame_id = "base_link";
    move_goal.target_pose.header.stamp = ros::Time::now();

    move_goal.target_pose.pose.position.x = 1.0;
    move_goal.target_pose.pose.orientation.w = 1.0;

    ROS_INFO("Sending goal");
    ac_ptr->sendGoal(move_goal);

    ac_ptr->waitForResult();

    if(ac_ptr->getState() == actionlib::SimpleClientGoalState::SUCCEEDED)
        ROS_INFO("Hooray, the base moved 1 meter forward");
    else
        ROS_INFO("The base failed to move forward 1 meter for some reason");
}


int main(int argc, char** argv){
    ros::init(argc, argv, "move");
    ros::NodeHandle n;

    //tell the action client that we want to spin a thread by default
    MoveBaseClient ac("move_base", true);
    ac_ptr = &ac;

    //wait for the action server to come up
    while(!ac.waitForServer(ros::Duration(5.0))){
        ROS_INFO("Waiting for the move_base action server to come up");
    }

    Server move_to_object(n, "bgu_move_to_object", boost::bind(&move_to_object_cb, _1, &move_to_object), false);
    move_to_object.start();

    ros::AsyncSpinner spinner(2);
    spinner.start();
    ros::waitForShutdown();

    return 0;
}