# Udacity_RoboSE_P5_HomeServiceRobot

_**Summary: The goal of this project is to simulate a turtlebot into our custom designed world in Gazebo using various ROS packages to spawn, localize, map, and navigate. Once everything is set up in the environment, the initial goal is to reach a pickup location for a marker. Once the robot graps the marker, the marker display is hidden. It then navigates to the final goal location and drops off the marker, making the marker visible again.**_

For this project, first you want to make sure that you have access to Linux. In the terminal, build the catkin workspace and initialize.

```
mkdir catkin_ws/src
cd catkin_ws/src
catkin_init_workspace
cd ..
catkin_make
```

You want to make sure that the code and files are up to date, so run `sudo apt-get update && sudo apt-get upgrade -y`. Once the catkin workspace is built and updated, the `clone` the following packages from github:
- https://github.com/turtlebot/turtlebot
- https://github.com/turtlebot/turtlebot_interactions
- https://github.com/turtlebot/turtlebot_simulator
- https://github.com/ros-perception/slam_gmapping

The syntax will be as follows:
`git clone https://github.com/turtlebot/turtlebot`

Source the package with `source devel/setup.bash` then intall the following using `rosdep`:

Package | Purpose
--------|--------
`turtlebot_teleop` | This package helps you manually naviagte the robot through the space. It will allow the `u i o j k l m , .` buttons on your keyboard to let move. To go forward, backward, left, and right, hold down on the `i , j l` keys respectively. The keys `u o m .` are diagonal movements NW, NE, SW, and SE respectively. You can tap on `q w e` buttons to increase max, linear, or angular speed by 10% respectively. Conversely, you can tap on `z x c` buttons to decrease max, linear, or angular speed by 10% respectively. The `k` key will kill all motion, whereas use of any other button not mentioned with smoothly stop motion. **Keys must be enetered in the teleop terminal.**
`turtlebot_rviz_launchers` | This package opens the ROS Visulaization (Rviz) applcation and allows you to visualize the project as a whole covering perception, decision-makng, and actuation. Initially Rviz is blank, but with `turtlbot_rviz_launchers` package, the Global Options, Global Status, Robot Model, TF, Laser Scan, Bumper Hit, Grid, Map, Pose Array, Camera, Map, Global Map, Local Map, AMCL Particle Swarm, and Full Plan  displays are set and mapped accoring to specificiations in shell scripts or the original turtlebot launch files. Rviz works together with all the launch files and scanners to depict a full system is working together, when configured properly.
`turtlebot_gazebo` | This package launches Gazebo and spawns the turtlebot in the Gazebo world file. Gazebo is a 3D simulator which allows creation of multidimensional models and enviroments to mimic real-world testing throught the use of physics specifications such as gravity or optics via a on-board camera. The eight key Gazebo features includes dynamics simulation, advanced 3D graphics, sensors, plugins, model database, socket-based communication, cloud simulation, and command line tools. Just like the previous package, this package allows customization by allowing modification of the spawning location, the robot model, or the built world file. This versalitilty allows for a wealth of similutated test scenarios to be run.

`gmapping` | allows autonomous naviation/ SLAM in the world

The syntax will be `rosdep -i install turtlebot_teleop`. Run `catkin_make` and `source devel/setup.bash` again, then you are ready to begin making your shell scripts which will allow you to run multiple terminals at once with various goals.

_**Make sure to `unzip map.zip` in `/my_robot/maps/map.zip`!!!**_


