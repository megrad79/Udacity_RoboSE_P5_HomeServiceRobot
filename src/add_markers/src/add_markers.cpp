#include <ros/ros.h>
#include <visualization_msgs/Marker.h>
#include <nav_msgs/Odometry.h>

bool pickUpZone = false;
bool dropOffZone = false;

void callback(const nav_msgs::Odometry::ConstPtr& msg)
{
  visualization_msgs::Marker pose;
  
  // function
  double x = msg->pose.pose.position.x;
  double y = msg->pose.pose.position.y;
  
  // goal 1 (-2,-1) >> pose(-1,2)
  if (-1.15 <= x <= -0.85 && 1.85 <= y <= 2.15){
    pickUpZone = true;
  }
  // goal 2 (0,-2) >> pose(-2,-0)
  else if (-2.15 <= x <= -1.85 && -0.15 <= y <= 0.15){
    dropOffZone=true;
  }
  else{
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
    marker.color.r = 0.0f;
    marker.color.g = 1.0f;
    marker.color.b = 0.0f;
    marker.color.a = 1.0;

    marker.lifetime = ros::Duration();

    // Publish the marker at goal 1 (-2,-1)
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
      marker_pub.publish(marker);
    }
    else if (pickUpZone == true && dropOffZone == false){
      // Wait 5 secs
      ros::Duration(5).sleep();
      // Set the marker action.  Options are ADD, DELETE, and new in ROS Indigo: 3 (DELETEALL)
      marker.action = visualization_msgs::Marker::DELETE;

      // Hide marker
      marker_pub.publish(marker);
    }
    else if (pickUpZone == false && dropOffZone == true){
      // Wait 5 secs
      ros::Duration(5).sleep();   
    
      // Set the pose of the marker to goal 2 (0,-2).
      marker.pose.position.x = -2;
      marker.pose.position.y = -0;
      marker.pose.position.z = 0;
      marker.pose.orientation.x = 0.0;
      marker.pose.orientation.y = 0.0;
      marker.pose.orientation.z = 0.0;
      marker.pose.orientation.w = 1.0;
    
      // Set the marker action.  Options are ADD, DELETE, and new in ROS Indigo: 3 (DELETEALL)
      marker.action = visualization_msgs::Marker::ADD;
    
      // Publish marker at goal 2
      marker_pub.publish(marker);
    }
    else {
      ros::spin();
    }
    
    r.sleep();
  }
}
