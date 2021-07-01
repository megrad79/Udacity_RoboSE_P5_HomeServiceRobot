#!/bin/sh
xterm -e " roslaunch turtlebot_gazebo turtlebot_world.launch world_file:=$(rospack find my_robot)/worlds/taryn.world" &
sleep 5
xterm -e " roslaunch turtlebot_gazebo gmapping_demo.launch map_file:=$(rospack find my_robot)/maps/map.yaml" &
sleep 5
xterm -e " roslaunch turtlebot_rviz_launchers view_navigation.launch map_file:=$(rospack find my_robot)/maps/map.yaml" &
sleep 5
xterm -e " roslaunch turtlebot_teleop keyboard_teleop.launch map_file:=$(rospack find my_robot)/maps/map.yaml"
