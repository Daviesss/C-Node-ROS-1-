#include "ros/ros.h"
#include "geometry_msgs/Twist.h"
#include "sensor_msgs/LaserScan.h"


class action{
   public:
      ros::NodeHandle nh;
      ros::Publisher velocity_pub = nh.advertise<geometry_msgs::Twist>("/cmd_vel",100);
      geometry_msgs::Twist velocity_messsage;
      void forward(){
        velocity_messsage.linear.x = 0.2;
        velocity_pub.publish(velocity_messsage);
      }
      void left_(){
        velocity_messsage.angular.z = -0.2;
        velocity_pub.publish(velocity_messsage);  
      }
};//main class action

void laser_callback(const sensor_msgs::LaserScanConstPtr& msg){
    action p;
    p.forward();
    float angle_min = msg->angle_min;
    float angle_max = msg->angle_max;
    float angle_increment = msg->angle_increment;
    float range_min = msg->range_min;
    float range_max = msg->range_max;
    std::vector<float> ranges = msg->ranges;

    ROS_INFO("Received LaserScan message");
    ROS_INFO("Angle Min: %f", angle_min);
    ROS_INFO("Angle Max: %f", angle_max);
    ROS_INFO("Angle Increment: %f", angle_increment);
    ROS_INFO("Range Min: %f", range_min);
    ROS_INFO("Range Max: %f", range_max);
    for (size_t i = 0; i < ranges.size(); ++i)
    {
        ROS_INFO("Range at index %zu: %f", i, ranges[i]);
    }

}

int main(int argc,char**argv){
    ros::init(argc,argv,"Visual_marker_node");
    ros::NodeHandle nh;
    ros::Subscriber laser_scan = nh.subscribe("/scan",1,laser_callback);
    ros::spin();

    return 0;
}