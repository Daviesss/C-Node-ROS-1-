#include "ros/ros.h"
#include "geometry_msgs/Twist.h"
#include "sensor_msgs/LaserScan.h"
#include "nav_msgs/Odometry.h"
#include "cmath"
#include "time.h"
using std::cout;
using std::cin;
using std::endl;


struct back{
    float speed = 0.2;
    void speed_(){
        geometry_msgs:: Twist velocity_message;
        velocity_message.linear.x = speed;
        velocity_message.angular.z = speed;
    }
};

//laser_callback class.
namespace laser_{
class laser_callback{
    public:
        ros::NodeHandle nh;
        ros::Publisher command_publisher=nh.advertise<geometry_msgs::Twist>("/cmd_vel",100);
        ros::Subscriber laser_call = nh.subscribe("/scan",100,laser_callbackk);
        ros::Subscriber odom_call = nh.subscribe("/odom",100,odom_callbackk);
        float odom_data;
        geometry_msgs::Twist velocity_message;
    void laser_callbackk(const sensor_msgs::LaserScanConstPtr& msg){
        ROS_INFO("The robot laser_callback:", msg->ranges);
        while (ros::ok()){
            forward();
            cout << "The robot moves forward" << endl;
        }
        if (msg->range_min < 1){
            rotate();
            cout << "The robot moves rotates" << endl;
        
        }
        else{
            forward();
        }
    }
    void backward_(){
        back p;
        p.speed_();
        command_publisher.publish(velocity_message);
    }
    void rotate(){
        velocity_message.linear.x = 0.0;
        velocity_message.angular.z = 0.2;
        command_publisher.publish(velocity_message);

    }
    
    void forward(){
        velocity_message.linear.x = 0.2;
        command_publisher.publish(velocity_message);
    }

    void odom_callbackk(const nav_msgs::OdometryConstPtr& data){
        data-> pose.pose.position;
        ROS_INFO("The odom data:",data->pose.pose.position);
        if (data->pose.pose.position.x == 2.0){
            velocity_message.linear.x = 0.0;
            velocity_message.angular.z = 0.0;
            command_publisher.publish(velocity_message); 
        }
        else{
            forward();
        }
    }

};
};

int main(int argc,char** argv){
    ros::init(argc,argv,"any_distance");
    laser_::laser_callback();
    return 0;
}