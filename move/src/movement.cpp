#include "ros/ros.h"
#include "geometry_msgs/Twist.h"
#include "cmath"
#include <iostream>
//class for movement

class left{
    public:
      double speed;
      ros::NodeHandle nh;
      ros::Publisher command_velocity_pub = nh.advertise<geometry_msgs::Twist>("/cmd_vel",100);
      geometry_msgs::Twist velocity_message;
    void left_drive(){
      drive_left__(0.2);
    }
  private:
    double drive_left__(double speed){
      velocity_message.angular.z = speed;
      command_velocity_pub.publish(velocity_message);
      }
};

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

//Main function
int main(int argc,char**argv){
    ros::init(argc,argv,"node_name"); 
    left p;
    p.left_drive();
    ros::spin();
    return 0;
}