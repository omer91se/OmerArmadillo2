//
// Created by tom on 22/11/16.
//

#include <ros/ros.h>
#include <control_msgs/GripperCommandAction.h>
#include <actionlib/client/simple_action_client.h>
#include <control_msgs/FollowJointTrajectoryAction.h>
#include <actionlib/server/simple_action_server.h>
#include <armadillo2_bgu/OperationAction.h>
#include <sensor_msgs/JointState.h>
#include <control_msgs/JointTrajectoryControllerState.h>

typedef actionlib::SimpleActionServer<armadillo2_bgu::OperationAction> Server;
typedef actionlib::SimpleActionClient<control_msgs::FollowJointTrajectoryAction> ArmClient;
typedef actionlib::SimpleActionClient<control_msgs::GripperCommandAction> GripperClient;

void activeCb();
void feedbackCb(const control_msgs::FollowJointTrajectoryFeedbackConstPtr& feedback);
void doneCb(const actionlib::SimpleClientGoalState& state, const control_msgs::FollowJointTrajectoryResultConstPtr& result);

void buildGoal(control_msgs::FollowJointTrajectoryGoal &goal);

float joints[6];
bool visited = false;

class ArmThrowNode {
private:
    ros::NodeHandle _nodeHandle;
    ros::AsyncSpinner _spinner;
    ros::Subscriber _feedbackListener;
    ArmClient _armClient;
    GripperClient _gripperClient;
    bool _needToOpen;
    bool _alreadyOpen;
    void doneCb(const actionlib::SimpleClientGoalState& state, const control_msgs::FollowJointTrajectoryResultConstPtr& result) {
        ROS_INFO("Finish in state [%s]", state.toString().c_str());
        //_needToOpen = !_needToOpen;
    }
    void feedbackCb(const control_msgs::FollowJointTrajectoryFeedbackConstPtr& feedback) {
        if((-M_PI / 4)  < feedback->actual.positions[1] && _needToOpen && !_alreadyOpen) {
            _alreadyOpen = true;
            ROS_INFO("OPEN %f", feedback->actual.positions[1]);
        }
    }
    void activeCb() {
        ROS_INFO("Arm is moving");
    }

    bool setGripperCmd(double pos, double effort = 0) {
        control_msgs::GripperCommandGoal goal;
        goal.command.position = pos;
        goal.command.max_effort = effort;

        _gripperClient.sendGoal(goal);
        _gripperClient.waitForResult();

        return _gripperClient.getState() == actionlib::SimpleClientGoalState::SUCCEEDED;

    }

    control_msgs::FollowJointTrajectoryGoal setGoalTja(double rotate1, double shoulder1, double shoulder2, double rotate2, double shoulder3, double wrist_joint) {
        control_msgs::FollowJointTrajectoryGoal goal;
        trajectory_msgs::JointTrajectoryPoint point;

        goal.trajectory.header.frame_id = "";
        goal.trajectory.header.stamp = ros::Time::now();
        goal.trajectory.joint_names.push_back("rotation1_joint");
        goal.trajectory.joint_names.push_back("shoulder1_joint");
        goal.trajectory.joint_names.push_back("shoulder2_joint");
        goal.trajectory.joint_names.push_back("rotation2_joint");
        goal.trajectory.joint_names.push_back("shoulder3_joint");
        goal.trajectory.joint_names.push_back("wrist_joint");

        point.time_from_start = ros::Duration(10.0);
        point.accelerations.resize(6);
        point.accelerations[4] = 2;
        point.positions.resize(goal.trajectory.joint_names.size());
        point.positions[0] = rotate1;
        point.positions[1] = shoulder1;
        point.positions[2] = shoulder2;
        point.positions[3] = rotate2;
        point.positions[4] = shoulder3;
        //point.positions[5] = joints[5]+pos;
        point.positions[5] = wrist_joint; //pos
        goal.trajectory.points.push_back(point);
        return goal;
    }

    bool setArmCmd(double rotate1, double shoulder1, double shoulder2, double rotate2, double shoulder3, double wrist_joint) {
        _armClient.sendGoal(setGoalTja(rotate1,shoulder1,shoulder2,rotate2,shoulder3,wrist_joint),
                            boost::bind(&ArmThrowNode::doneCb, this, _1, _2),
                            boost::bind(&ArmThrowNode::activeCb, this),
                            ArmClient::SimpleFeedbackCallback());
        _armClient.waitForResult();
        return _armClient.getState() == actionlib::SimpleClientGoalState::SUCCEEDED;
    }

public:
    ArmThrowNode() : _nodeHandle(), _spinner(1),_armClient( "arm_trajectory_controller/follow_joint_trajectory"), _gripperClient("gripper_controller/gripper_cmd") {
        _feedbackListener = _nodeHandle.subscribe("arm_trajectory_controller/state", 10, &ArmThrowNode::feedbackCb, this);

        _spinner.start();
        _armClient.waitForServer();
        _gripperClient.waitForServer();

        _needToOpen = false;
        _alreadyOpen = false;


    }

    void open_gripper() {
        setGripperCmd(0.14);
    }

    void close_gripper() {
        setGripperCmd(0.01, 0.007);
    }

    void fixed_pour() {
      //  setArmCmd(0,0.1);
        std::cout<<joints[5]<<std::endl;
        setArmCmd(joints[0],joints[1],joints[2],0,joints[4],2.15);
        ros::Duration(1.5).sleep();
        setArmCmd(joints[0],joints[1],joints[2],0,joints[4],joints[5]);
    }

    void extend_arm() {
        setArmCmd(0.0,0.37,0.-0.25,0.0,0.57,0.00);
        ros::Duration(2).sleep();
        //setArmCmd(0.0,0.0,0.0,2.5,-1.38,0.00);
    }

};

void subCB(const control_msgs::JointTrajectoryControllerStateConstPtr jointStates){
    joints[0] = jointStates->actual.positions[0];
    joints[1] = jointStates->actual.positions[1];
    joints[2] = jointStates->actual.positions[2];
    joints[3] = jointStates->actual.positions[3];
    joints[4] = jointStates->actual.positions[4];
    if(!visited) {
        joints[5] = jointStates->actual.positions[5];
        visited =true;
    }

}


void pour(const armadillo2_bgu::OperationGoalConstPtr& goal, Server* as){
    ROS_INFO("POUR: In CB");
    ArmThrowNode armThrowNode;
    armThrowNode.fixed_pour();

    as->setSucceeded();
}
void give(const armadillo2_bgu::OperationGoalConstPtr& goal, Server* as){
    ROS_INFO("GIVE: In CB");
    ArmThrowNode armThrowNode;
    armThrowNode.extend_arm();

    as->setSucceeded();
}
void open(const armadillo2_bgu::OperationGoalConstPtr& goal, Server* as){
    ROS_INFO("OPEN: In CB");
    ArmThrowNode armThrowNode;
    armThrowNode.open_gripper();


//*****Action Callbacks******
}
void doneCb(const actionlib::SimpleClientGoalState& state, const control_msgs::FollowJointTrajectoryResultConstPtr& result) {
    ROS_INFO("Finish in state [%s]", state.toString().c_str());
//    ROS_INFO_STREAM((*result));
    ros::shutdown();
}

void feedbackCb(const control_msgs::FollowJointTrajectoryFeedbackConstPtr& feedback) {
    //ROS_INFO("%f", feedback->actual.positions[1]);
    static bool isOpen = false;
    if((-M_PI / 4)  < feedback->actual.positions[1] && !isOpen) {
        isOpen = true;
        ROS_INFO("OPEN %f", feedback->actual.positions[1]);
        GripperClient gripperClient("gripper_controller/gripper_cmd", true);
        gripperClient.waitForServer();
        control_msgs::GripperCommandGoal openGoal;
        openGoal.command.position = 0.14;
        gripperClient.sendGoal(openGoal);
        ROS_INFO("SEND TO GRIPPER");
        gripperClient.waitForResult();
        ROS_INFO("GRIPPER IS OPEN");

    }
}

void activeCb() {
    ROS_INFO("Arm is moving");
}

int main(int argc, char** argv) {
    ros::init(argc, argv, "manipulation");

    std::cout<<"manipulation online"<<std::endl;
    ros::NodeHandle n;

    ros::Subscriber sub = n.subscribe("/arm_trajectory_controller/state", 1000, subCB);
    Server pourServer(n, "bgu_pour", boost::bind(&pour, _1, &pourServer), false);
    Server giveServer(n, "bgu_extend", boost::bind(&give, _1, &giveServer), false);
    Server openServer(n, "bgu_open",boost::bind(&open,_1,&openServer),false);

    ros::AsyncSpinner spinner(4);
    giveServer.start();
    pourServer.start();
    openServer.start();
    spinner.start();
    ros::waitForShutdown();


    return 0;
}


