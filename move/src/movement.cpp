#include "ros/ros.h"
#include "geometry_msgs/Twist.h"
#include "sensor_msgs/LaserScan.h"
#include "cmath"
#include <iostream>
//class for movement
namespace uiuc{
class move{
public:
  ros::NodeHandle nh;
  int speed = 0.2;
  ros::Publisher command_publish = nh.advertise<geometry_msgs::Twist>("/cmd_vel",10);
//robot drives forward  
void drive_forward(){
  while(ros::ok()){
    geometry_msgs::Twist velocity_message;
    velocity_message.linear.x = 0.2;
    command_publish.publish(velocity_message);
    ROS_INFO("The robot is driving forward");
  }
}
void drive_backward(int speed){
  while(ros::ok()){
    geometry_msgs::Twist velocity_message;
    velocity_message.linear.x = -speed;
    command_publish.publish(velocity_message);
    ROS_INFO("The robot is driving backward");
  }
}
};
  };
int main(int argc,char**argv){
    ros::init(argc,argv,"node_name"); 
    uiuc::move m;
    m.drive_forward();//calling the drive forward method
    // m.drive_backward(0.2);
    ros::spin();
    return 0;
}