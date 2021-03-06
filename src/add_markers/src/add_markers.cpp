#include <ros/ros.h>
#include <visualization_msgs/Marker.h>
#include <nav_msgs/Odometry.h>

// Zones
bool pickUpZone = false;
bool dropOffZone = false;

void callback(const nav_msgs::Odometry::ConstPtr& msg)
{
  visualization_msgs::Marker pose;
  
  // function
  double x = msg->pose.pose.position.x;
  double y = msg->pose.pose.position.y;

  double delta = 0.15;

  // Goal 1 Coordinates
  int x1 = -1;
  int y1 = 2;

  // Goal 2 Coordinates
  int x2 = -2;
  int y2 = 0;
  
  // goal 1 (-2,-1) >> pose(-1,2)
  if (x1-delta <= x <= x1+delta && y1-delta <= y <= y1+delta){
    pickUpZone = true;
    dropOffZone = false;
  }
  // goal 2 (0,-2) >> pose(-2,-0)
  else if (x2-delta <= x <= x2+delta && y2-delta <= y <= y2+delta){
    pickUpZone = false;
    dropOffZone = true;
  }
  else {
    pickUpZone = false;
    dropOffZone = false;
  }
  
}

int main( int argc, char** argv )
{
  ros::init(argc, argv, "add_markers");   // Initialize add_markers
  ros::NodeHandle n;   // Create handle  
  ros::Rate r(1);   // Set rate
  ros::Publisher marker_pub = n.advertise<visualization_msgs::Marker>("visualization_marker", 1);   // Create publishers that can publish visualization_msgs::Marker on visualization_marker  
  ros::Subscriber odom_sub = n.subscribe("odom", 1, callback);   // Create subscribers
  
  // Set our initial shape type to be a cube
  uint32_t shape = visualization_msgs::Marker::CUBE;

  while (ros::ok())
  {
    visualization_msgs::Marker marker;
    // Set the frame ID and timestamp.  See the TF tutorials for information on these.
    marker.header.frame_id = "map";
    marker.header.stamp = ros::Time::now();

    // Set the namespace and id for this marker.  This serves to create a unique ID
    // Any marker sent with the same namespace and id will overwrite the old one
    marker.ns = "add_markers";
    marker.id = 0;

    // Set the marker type.  Initially this is CUBE, and cycles between that and SPHERE, ARROW, and CYLINDER
    marker.type = shape;

    // Set the marker action.  Options are ADD, DELETE, and new in ROS Indigo: 3 (DELETEALL)
    marker.action = visualization_msgs::Marker::ADD;

    // Set the pose of the marker to goal 1.  This is a full 6DOF pose relative to the frame/time specified in the header
    marker.pose.position.x = -1;
    marker.pose.position.y = 2;
    marker.pose.position.z = 0;
    marker.pose.orientation.x = 0.0;
    marker.pose.orientation.y = 0.0;
    marker.pose.orientation.z = 0.0;
    marker.pose.orientation.w = 1.0;

    // Set the scale of the marker -- 1x1x1 here means 1m on a side
    marker.scale.x = 0.15;
    marker.scale.y = 0.15;
    marker.scale.z = 0.15;

    // Set the color -- be sure to set alpha to something non-zero!
    marker.color.r = 0.5f;
    marker.color.g = 0.0f;
    marker.color.b = 0.5f;
    marker.color.a = 1.0;

    marker.lifetime = ros::Duration();


    // Marker 2*********************************************************************************
    visualization_msgs::Marker marker2;
    // Set the frame ID and timestamp.  See the TF tutorials for information on these.
    marker2.header.frame_id = "map";
    marker2.header.stamp = ros::Time::now();

    // Set the namespace and id for this marker.  This serves to create a unique ID
    // Any marker sent with the same namespace and id will overwrite the old one
    marker2.ns = "add_markers";
    marker2.id = 0;

    // Set the marker type.  Initially this is CUBE, and cycles between that and SPHERE, ARROW, 	and CYLINDER
    marker2.type = shape;

    // Set the pose of the marker to goal 2 (0,-2).
    marker2.pose.position.x = -2;
    marker2.pose.position.y = -0;
    marker2.pose.position.z = 0;
    marker2.pose.orientation.x = 0.0;
    marker2.pose.orientation.y = 0.0;
    marker2.pose.orientation.z = 0.0;
    marker2.pose.orientation.w = 1.0;

    // Set the scale of the marker -- 1x1x1 here means 1m on a side
    marker2.scale.x = 0.15;
    marker2.scale.y = 0.15;
    marker2.scale.z = 0.15;

    // Set the color -- be sure to set alpha to something non-zero!
    marker2.color.r = 0.5f;
    marker2.color.g = 0.0f;
    marker2.color.b = 0.5f;
    marker2.color.a = 1.0;

    marker2.lifetime = ros::Duration();

    while (marker_pub.getNumSubscribers() < 1)
    {
      if (!ros::ok())
      {
        return 0;
      }
      ROS_WARN_ONCE("Please create a subscriber to the marker");
      sleep(1);
    }


    if (pickUpZone == false && dropOffZone == false){

      // Publish the marker at goal 1 (-2,-1)
      marker_pub.publish(marker);
      
      // Wait 5 secs
      ros::Duration(5).sleep();

      // Hide the marker action.  Options are ADD, DELETE, and new in ROS Indigo: 3 (DELETEALL)
      marker.action = visualization_msgs::Marker::DELETE;
      marker_pub.publish(marker);

      // Wait 5 secs
      ros::Duration(5).sleep();
    }
    else {
      
      // Set the marker action.  Options are ADD, DELETE, and new in ROS Indigo: 3 (DELETEALL)
      marker2.action = visualization_msgs::Marker::ADD;

      // Publish marker at goal 2
      marker_pub.publish(marker2);
   }
    

    r.sleep();
  }
}

