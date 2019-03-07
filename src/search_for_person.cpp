#include "ros/ros.h"
#include <geometry_msgs/Twist.h>
#include <trajectory_msgs/JointTrajectory.h>
#include <geometry_msgs/PoseStamped.h>
#include <actionlib/server/simple_action_server.h>
#include <armadillo2_bgu/OperationAction.h>

typedef actionlib::SimpleActionServer<armadillo2_bgu::OperationAction> Server;

double PI = PI = 3.1415926535897;
ros::Publisher pub;
ros::Publisher pan_tilt_pub;
bool found_person = false;
bool start_looking = false;
void move_head(double pan, double tilt);


void find_person();

void poseCB(const geometry_msgs::PoseStamped::ConstPtr& msg) {
    if(start_looking)
        std::cout<<"msg->pose.position.z: "<<msg->pose.position.z<<std::endl;
        if(msg->pose.position.z < 0.85)
            found_person = true;
}

void find_person(){
      ros::Duration loop_rate(1.0);
      geometry_msgs::Twist msg;
      msg.angular.z = 0;
      int count = 0;
      while(ros::ok() && count < 1){ 
            //face detection stuff
            msg.angular.z = PI/16;
            
            pub.publish(msg);
            loop_rate.sleep();
            if(found_person)
                count++;            
            
      }
      msg.angular.z = 0;
      pub.publish(msg);
      found_person = false;
      start_looking = false;
}

void move_head(double pan, double tilt){
    ros::Duration loop_rate(1.0);
    int i = 0;
    while(ros::ok() && i < 2){
        i++;
        ROS_INFO("Publishing pan tilt");
        trajectory_msgs::JointTrajectory traj;
        traj.header.stamp = ros::Time::now();
        traj.joint_names.push_back("head_pan_joint");
        traj.joint_names.push_back("head_tilt_joint");
        traj.points.resize(1);
        traj.points[0].time_from_start = ros::Duration(1.0);
        std::vector<double> q_goal(2);

        //ROS_INFO("pan: %f, tilt: %f", pan_goal*180/M_PI, tilt_goal*180/M_PI);

        q_goal[0] = pan;
        q_goal[1] = tilt;
        traj.points[0].positions=q_goal;
        traj.points[0].velocities.push_back(0.1);
        traj.points[0].velocities.push_back(0.1);
        pan_tilt_pub.publish(traj);
        loop_rate.sleep();
        //ros::spinOnce();
    }
}
void execute(const armadillo2_bgu::OperationGoalConstPtr& goal, Server* as) 
{
    
	ros::Duration loop_rate(5.0);
    ROS_INFO("[search_for_person]: in execute Callback");
    start_looking = true;
    armadillo2_bgu::OperationResult result_;

    move_head(0,-0.02);
    loop_rate.sleep();
    find_person();

    if(true) 
        as->setSucceeded(result_);
    else
        as->setAborted();
    
}

int main(int argc, char **argv){
    ros::init(argc, argv, "search_for_person");
    ros::NodeHandle nh;

    Server server(nh, "bgu_searchforperson", boost::bind(&execute, _1, &server), false);
    server.start();

    pub = nh.advertise<geometry_msgs::Twist>("cmd_vel", 1000);

    pan_tilt_pub = nh.advertise<trajectory_msgs::JointTrajectory>("/pan_tilt_trajectory_controller/command", 5);

    ros::Subscriber sub = nh.subscribe("/find_objects_node/object_pose", 100, poseCB);
   
    ros::spin();
}


