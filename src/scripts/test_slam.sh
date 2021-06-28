#!/bin/sh
xterm -e " source /opt/ros/kinetic/setup.bash; roscore" &
sleep 5
xterm -e " roslaunch turtlebot_gazebo turtlebot_world.launch world_file:=/home/workspace/catkin_ws/src/my_robot/worlds/taryn.world" &
sleep 2
xterm -e " roslaunch turtlebot_gazebo gmapping_demo.launch" &
sleep 2
xterm -e " roslaunch turtlebot_rviz_launchers view_navigation.launch" &
sleep 2
xterm -e " roslaunch turtlebot_teleop keyboard_teleop.launch"
