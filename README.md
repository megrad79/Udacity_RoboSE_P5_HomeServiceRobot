# Udacity_RoboSE_P5_HomeServiceRobot

The goal of this project is to simulate a turtlebot into our custom designed world in Gazebo using various ROS packages to spawn, localize, map, and navigate. Once everything is set up in the environment, the initial goal is to reach a pickup location for a marker. Once the robot graps the marker, the marker display is hidden. It then navigates to the final goal location and drops off the marker, making the marker visible again.

Once the catkin workspace is built and, the follow packages are cloned from github:
- https://github.com/turtlebot/turtlebot
- https://github.com/turtlebot/turtlebot_interactions
- https://github.com/turtlebot/turtlebot_simulator
- https://github.com/ros-perception/slam_gmapping

Source the package then intall the following using rosdep:
turtlebot_teleop
turtlebot_rviz_launchers
turtlebot_gazebo
gmapping

Run catking_make and source the package again, then you are ready to begin making your shell scripts which will allow you to run multiple terminals at once with various goals.

**Make sure to unzip map.zip in /my_robot/maps/map.zip.**
