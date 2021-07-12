# Udacity_RoboSE_P5_HomeServiceRobot

_**Summary:** The goal of this project is to simulate a turtlebot into our custom designed world in Gazebo using various ROS packages to spawn, localize, map, and navigate. Once everything is set up in the environment, the initial goal is to reach a pickup location for a marker. Once the robot graps the marker, the marker display is hidden. It then navigates to the final goal location and drops off the marker, making the marker visible again._

For this project, first you want to make sure that you have access to Linux. In the terminal, build the catkin workspace and initialize.
`mkdir catkin_ws/src
cd catkin_ws/src
catkin_init_workspace
cd ..
catkin_make`

You want to make sure that the code and files are up to date, so run 'sudo apt-get update && sudo apt-get upgrade -y`. Once the catkin workspace is built and updated, the `clone` the following packages from github:
- https://github.com/turtlebot/turtlebot
- https://github.com/turtlebot/turtlebot_interactions
- https://github.com/turtlebot/turtlebot_simulator
- https://github.com/ros-perception/slam_gmapping

The syntax will be as follows:
`git clone https://github.com/turtlebot/turtlebot`

Source the package with `source devel/setup.bash` then intall the following using `rosdep`:

Package | Purpose
--------|--------
`turtlebot_teleop` | helps you manually naviagte the robot through the space
`turtlebot_rviz_launchers` | allows you to visualize various sensors and planning algorithms as the robot navigates the space
`turtlebot_gazebo` | launches gazebo and spawns the robot in the gazebo world
`gmapping` | allows autonomous naviation/ SLAM in the world

The syntax will be `rosdep -i install turtlebot_teleop`. Run `catkin_make` and `source devel/setup.bash` again. Now, you're ready to start making your code.

Run `catkin_make` and `source` the package again, then you are ready to begin making your shell scripts which will allow you to run multiple terminals at once with various goals.

**Make sure to `unzip map.zip` in `/my_robot/maps/map.zip`.**
