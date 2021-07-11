bool pickUpZone = false;
bool dropOffZone = false;

// Goal 1 Coordinates
int x1 = 0; // 
int y1 = 0; //
int goal1[2] = [x1, y1];

// Goal 2 Coordinates
int x2 = 0; //
int y2 = 0; //
int goal2[2] = [x2, y2];

// Location defined
int delta = 0.15; 
int x = pose.position.position.x;
int y = pose.position.position.y;
int location[2] = [x,y];


if (x1-delta <= x <= x1+delta && y1-delta <= y <= y1+delta){
  pickUpZone = true;
  dropOffZone = false;
  location = goal1;
}
else if (x2-delta <= x <= x2+delta && y2-delta <= y <= y2+delta){
  pickUpZone = false;
  dropOffZone = true;
  location = goal2;
}
else {
  pickUpZone = false;
  dropOffZone = false;
  location = location;
}


switch(location){
  case g1:
    // enter mark part 1
    break;
  case g2:
    // enter mark part 2
    break;
  case location:
    // enter mark part other
    break;
}


///
marker.lfetime = ros::Duration(5);
t=0 => marker add; // goal 1

ros::Duration(5).sleep();   
t=5 => marker delete;

marker.header.stamp = ros::Time::now();
marker.lfetime = ros::Duration();
marker.action = visualization_msgs::Marker::ADD;
t=10+ => marker add; //goal 2
