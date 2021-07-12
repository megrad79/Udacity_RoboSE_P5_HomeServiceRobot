# Udacity_RoboSE_P5_HomeServiceRobot

_**Summary: The goal of this project is to simulate a turtlebot into our custom-designed world in Gazebo using various ROS packages to spawn, localize, map, and navigate. The initial goal is to reach a pickup location for a marker. Once the robot grasps the marker, the marker display is hidden. It then navigates to the final goal location and drops off the marker, making the marker visible again.**_

For this project, first, make sure there is access to Linux. In the terminal, build the catkin workspace and initialize.

```
mkdir catkin_ws/src
cd catkin_ws/src
catkin_init_workspace
cd ..
catkin_make
```

Ensure that the code and files are up to date, so run `sudo apt-get update && sudo apt-get upgrade -y`. Once the catkin workspace is built and updated, `clone` the following packages from GitHub:
- https://github.com/turtlebot/turtlebot
- https://github.com/turtlebot/turtlebot_interactions
- https://github.com/turtlebot/turtlebot_simulator
- https://github.com/ros-perception/slam_gmapping

The syntax will be as follows:
`git clone https://github.com/turtlebot/turtlebot`

Source the package with `source devel/setup.bash` then install the following using `rosdep`:

Package | Purpose
--------|--------
`turtlebot_teleop` | This package enables manual navigation the robot through space. It will allow the `u i o j k l m , .` buttons on your keyboard to let you move. To go forward, backward, left, and right, hold down on the `i , j l` keys, respectively. The keys `u o m .` are diagonal movements NW, NE, SW, and SE, individually. Tap on `q w e` buttons to increase max, linear, or angular speed by 10%. Conversely, tap on `z x c` buttons to decrease max, linear, or angular speed by 10%. The `k` key will kill all motion, whereas the use of any other button not mentioned will smoothly stop motion. **Keys must be entered in the teleop terminal.** The `keyboard_teleop.launch` file will be used for this project. 
`turtlebot_rviz_launchers` | This package opens the ROS Visualization (Rviz) application and allows you to visualize the project as a whole, covering perception, decision-making, and actuation. Initially, Rviz is blank. With the `turtlbot_rviz_launchers` package, the Global Options, Global Status, Robot Model, TF, Laser Scan, Bumper Hit, Grid, Map, Pose Array, Camera, Map, Global Map, Local Map, AMCL Particle Swarm, and Full Plan displays are set and mapped according to specifications in shell scripts or the original turtlebot launch files. Rviz works together with all the launch files and scanners to depict that a complete system works together when appropriately configured. The `view_navigation.launch` file will be used for this project. 
`turtlebot_gazebo` | This package launches Gazebo and spawns the turtlebot in the Gazebo world file. Gazebo is a 3D simulator that allows the creation of multidimensional models and environments to mimic real-world testing by using physics specifications such as gravity or optics via an onboard camera. The eight key Gazebo features include dynamics simulation, advanced 3D graphics, sensors, plugins, model database, socket-based communication, cloud simulation, and command-line tools. Like the previous package, this package allows customization by modifying the spawning location, the robot model, or the built world file. This versatility allows for a wealth of simulated test scenarios to be run. The `turtlebot_world.launch` file will be used for this project. 
`gmapping` | This package allows autonomous navigation. Through the utilization of lasers and RGB-D cameras, the robot can use Simultaneous Localization And Mapping (SLAM). With SLAM in process, the robot can then stitch together a map of the world. The `gmapping_demo.launch` file will be used for this project. 

The syntax will be `rosdep -i install turtlebot_teleop`. Run `catkin_make` and `source devel/setup.bash` again, then begin making shell scripts that will allow multiple terminals to run simultaneously with various goals.


### _**Make sure to `unzip map.zip` in `/my_robot/maps/map.zip`.**_


1. Create a shell script entitled `test_slam.sh` to launch the following: 
- `turtlebot_world.launch`
- `gmapping_demo.launch`
- `view_navigation.launch`
- `keyboard_teleop.launch`

  This will launch Gazebo and Rviz while utlizing SLAM to capture a map of the enviroment.

2. Create a shell script entitled `test_navigation.sh` to launch the following: 
- `turtlebot_world.launch`
- `amcl_demo.launch`
- `view_navigation.launch`

  This will launch Gazebo and Rviz while utlizing a particle filter to determine the robot trajectory when given goal destinations.

3. Create a package entitled `pick_objects` with `move_base_msgs`, `actionlib`, and `roscpp` dependencies and a `pick_objects.cpp` node with two goal destinations. Then create a shell script entitled `pick_objects.sh` to launch the following: 
- `turtlebot_world.launch`
- `amcl_demo.launch`
- `view_navigation.launch`
- `pick_objects`

  This will launch Gazebo and Rviz with a particle filter to determine the best robot trajectory given the two goal destinations in `pick_objects.cpp`.

4. Create a package entitled `add_markers` with `visualization_msgs` and `roscpp` dependencies and a `add_markers.cpp` node with two goal destinations. Then create a shell script entitled `add_markers.sh` to launch the following: 
- `turtlebot_world.launch`
- `amcl_demo.launch`
- `view_navigation.launch`
- `add_markers`

  This will launch Gazebo and Rviz with a particle filter for determining trajectory. However, this code will mainly focus on displaying a marker in Rviz before the robot reaches the goal 1 location, deleting the marker, then adding it again when it reaches the goal 2 destination in `add_markers.cpp`.

5. Finally, create a shell script entitled `home_service.sh` to launch the following: 
- `turtlebot_world.launch`
- `amcl_demo.launch`
- `view_navigation.launch`
- `pick_objects`
- `add_markers`

  This will launch Gazebo, Rviz, the particle filter, `pick_objects.cpp`, and `add_markers.cpp` for a enviroment that will display a marker at a goal 1 location, navigate the robot autonomously to the goal 1/ marker, hide the marker while picking it up, navigate to goal 2 location, and dropp off the marker making it visible again.

