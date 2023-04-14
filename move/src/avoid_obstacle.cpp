#include "ros/ros.h"
#include "geometry_msgs/Twist.h"
#include "sensor_msgs/LaserScan.h"

void laser_callback(const sensor_msgs::LaserScanPtr& msg){
    ros::NodeHandle nh;
    ros::Publisher command_pub = nh.advertise<geometry_msgs::Twist>("/cmd_vel",10);
    for (size_t i = 0; i < msg->ranges.size(); ++i){
    ROS_INFO("Range[%zu]: %.2f", i, msg->ranges[i]);
    if (msg->range_min< 1){
        geometry_msgs::Twist velocity_message;
        velocity_message.angular.z = 0.2;
        command_pub.publish(velocity_message);
  }
  }
}

int main(int argc,char**argv){
    ros::init(argc,argv,"obstacle_avoidance");
    ros::NodeHandle nh;
    ros::Subscriber laser_sub = nh.subscribe("/scan",10,laser_callback);
    ros::spin();

    return 0;
}
