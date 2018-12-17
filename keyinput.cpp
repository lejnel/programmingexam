#include "ros/ros.h"
#include "geometry_msgs/Twist.h"
#include <sstream>
#include "turtlesim/Pose.h"
#include <iostream>
#include "std_msgs/String.h"
ros::Publisher pub;
ros::Subscriber pose_subscriber;
ros::Subscriber UI;

using namespace std;

const double PI =3.14159265359;

bool done = false;
int xr;	// x coordinate of the turtle in turtlesim
int yr;	// y coordinate of the turtle in turtlesim
int dr;	// looking direction of the turtle in turtlesim
string ans;

void decidingtheoutput ()
{

}

void chatterCallback(const std_msgs::String::ConstPtr& msg)
{
	ans = msg->data;
  ROS_INFO("I heard:[%s]", ans);
}
  int main(int argc, char**argv){
  ros::init(argc, argv, "publish_velocity");
  ros::NodeHandle n;
	ros::Subscriber sub = n.subscribe("Commands", 10, chatterCallback);
  //pose_subscriber = n.subscribe("/turtle1/pose",10 , poseCallback);
  pub = n.advertise<geometry_msgs::Twist>("/turtle1/cmd_vel", 1);
  ros::Rate rate(10);
  while(ros::ok()){
					geometry_msgs::Twist msg;
		if(ans == "w") {
			msg.linear.x = 1;
			msg.angular.z = 0;
						pub.publish(msg);
		}
		else if(ans == "a"){
			msg.linear.x = 0;
			msg.angular.z = 10;
						pub.publish(msg);
		}
		else if (ans == "s"){
			msg.linear.x = -1;
			msg.angular.z = 0;
						pub.publish(msg);
		}
		else if (ans == "d"){
			msg.linear.x = 0;
			msg.angular.z = -10;
						pub.publish(msg);
		}
		else if (ans == "x"){
			msg.linear.x = 0;
			msg.angular.z = 0;
						pub.publish(msg);
		}

		  ros::spinOnce();
		  rate.sleep();

	}
			return 0;
	}