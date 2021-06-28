#include <ros/ros.h>
#include <move_base_msgs/MoveBaseAction.h>
#include <actionlib/client/simple_action_client.h>

typedef actionlib::SimpleActionClient<move_base_msgs::MoveBaseAction> MoveBaseClient;

int main(int argc, char** argv){
  ros::init(argc, argv, "pick_objects");

  //tell the action client that we want to spin a thread by default
  MoveBaseClient ac("move_base", true);

  //wait for the action server to come up
  while(!ac.waitForServer(ros::Duration(5.0))){
    ROS_INFO("Waiting for the move_base action server to come up");
  }

  move_base_msgs::MoveBaseGoal goal;

  //we'll send a goal to the robot to move 1 meter forward
  goal.target_pose.header.frame_id = "map";
  goal.target_pose.header.stamp = ros::Time::now();

  goal.target_pose.pose.position.x = 1.0;
  goal.target_pose.pose.orientation.w = 1.0;

  ROS_INFO("Sending goal");
  ac.sendGoal(goal);

  ac.waitForResult();

  if(ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED){
    ROS_INFO("Robot reached its 1st goal! ^-^");
  } 
  else {
    ROS_INFO("Robot FAILED to reach its 1st goal! >:[");
  }

  // Wait 5 secs
  ros::Duration(5).sleep();


  // Goal 2
  move_base_msgs::MoveBaseGoal goal2;

  //we'll send a goal to the robot to move 1 meter forward
  goal2.target_pose.header.frame_id = "map";
  goal2.target_pose.header.stamp = ros::Time::now();

  goal2.target_pose.pose.position.x = -1.0;
  goal2.target_pose.pose.orientation.w = -1.0;

  ROS_INFO("Sending goal 2");
  ac.sendGoal(goal2);


  if(ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED){
    ROS_INFO("Robot reached its 2nd goal! ^-^");
  }
  else {
    ROS_INFO("Robot FAILED to reach its 2nd goal! >:[");
  }

  return 0;
}

