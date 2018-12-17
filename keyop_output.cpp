#include "ros/ros.h"
#include "turtlesim/Pose.h"
#include "turtlesim/Color.h"
#include "std_msgs/String.h"
#include <iostream>
#include <sstream>

using namespace std;
ros::Publisher pub1;

// Topic messages callback
//pose_callback
void UI(){

char option;
std_msgs::String msg;
stringstream ss;

cout << "Introduction to what the user can do here"<<endl;
  cout << "Choose one of the following options:"<<endl;
   cout << "Press w to go forward " <<endl;
    cout << "Press a to go right " <<endl;
  cout << "Press s to go back " <<endl;
   cout << "Press d to go to the left" <<endl;
      cout << "Press x to stop" <<endl;

cin >> option;


     switch(option)
     {
case ('w'):
    ss << "w";
    msg.data = ss.str();

         break;

case ('a'):

     ss << "a";
     msg.data = ss.str();

         break;

 case ('s'):

     ss << "s";
     msg.data = ss.str();

        break;

case ('d'):

     ss << "d";
     msg.data = ss.str();

          break;

          case ('x'):

               ss << "x";
               msg.data = ss.str();

                    break;

        }
    pub1.publish(msg);
    ros::spinOnce();
return;
}

int main(int argc, char **argv)
{
 ros::init(argc, argv, "talker");
 ros::NodeHandle node;


 pub1 = node.advertise<std_msgs::String>("Commands", 1);



    // Enter a loop.
    while(ros::ok()){
keyfeedback_function();

UI();

ros::spinOnce();
}
    return 0;
}


/*
class TurtlebotTeleop
{
public:
  TurtlebotTeleop();
  void keyLoop();
  void watchdog();

private:

  
  ros::NodeHandle nh_,ph_;
  double linear_, angular_;
  ros::Time first_publish_;
  ros::Time last_publish_;
  double l_scale_, a_scale_;
  ros::Publisher vel_pub_;
  void publish(double, double);
  boost::mutex publish_mutex_;

};
*/

/*
TurtlebotTeleop::TurtlebotTeleop():
  ph_("~"),
  linear_(0),
  angular_(0),
  l_scale_(1.0),
  a_scale_(1.0)
{
  ph_.param("scale_angular", a_scale_, a_scale_);
  ph_.param("scale_linear", l_scale_, l_scale_);

  vel_pub_ = nh_.advertise<geometry_msgs::Twist>("cmd_vel", 1);
}
*/
/*
int kfd = 0;
struct termios cooked, raw;
*/

/*
void quit(int sig)
{
  tcsetattr(kfd, TCSANOW, &cooked);
  ros::shutdown();
  exit(0);
}
*/

/*
int main(int argc, char** argv)
{
  ros::init(argc, argv, "turtlebot_teleop");
  TurtlebotTeleop turtlebot_teleop;
  ros::NodeHandle n;

  signal(SIGINT,quit);

  boost::thread my_thread(boost::bind(&TurtlebotTeleop::keyLoop, &turtlebot_teleop));
  
  
  ros::Timer timer = n.createTimer(ros::Duration(0.1), boost::bind(&TurtlebotTeleop::watchdog, &turtlebot_teleop));

  ros::spin();

  my_thread.interrupt() ;
  my_thread.join() ;
      
  return(0);
}
*/

/*
void TurtlebotTeleop::watchdog()
{
  boost::mutex::scoped_lock lock(publish_mutex_);
  if ((ros::Time::now() > last_publish_ + ros::Duration(0.15)) && 
      (ros::Time::now() > first_publish_ + ros::Duration(0.50)))
    publish(0, 0);
}
*/

/*
void TurtlebotTeleop::keyLoop()
{
  char c;


  // get the console in raw mode                                                              
  tcgetattr(kfd, &cooked);
  memcpy(&raw, &cooked, sizeof(struct termios));
  raw.c_lflag &=~ (ICANON | ECHO);
  // Setting a new line, then end of file                         
  raw.c_cc[VEOL] = 1;
  raw.c_cc[VEOF] = 2;
  tcsetattr(kfd, TCSANOW, &raw);

  puts("Reading from keyboard");
  puts("---------------------------");
  puts("Use arrow keys to move the turtlebot.");


  while (ros::ok())
  {
    // get the next event from the keyboard  
    if(read(kfd, &c, 1) < 0)
    {
      perror("read():");
      exit(-1);
    }


    linear_=angular_=0;
    ROS_DEBUG("value: 0x%02X\n", c);
  
    switch(c)
    {
      case KEYCODE_L:
        ROS_DEBUG("LEFT");
        angular_ = 1.0;
        break;
      case KEYCODE_R:
        ROS_DEBUG("RIGHT");
        angular_ = -1.0;
        break;
      case KEYCODE_U:
        ROS_DEBUG("UP");
        linear_ = 1.0;
        break;
      case KEYCODE_D:
        ROS_DEBUG("DOWN");
        linear_ = -1.0;
        break;
    }
    boost::mutex::scoped_lock lock(publish_mutex_);
    if (ros::Time::now() > last_publish_ + ros::Duration(1.0)) { 
      first_publish_ = ros::Time::now();
    }
    last_publish_ = ros::Time::now();
    publish(angular_, linear_);
  }

  return;
}
*/

/*
void TurtlebotTeleop::publish(double angular, double linear)  
{
    geometry_msgs::Twist vel;
    vel.angular.z = a_scale_*angular;
    vel.linear.x = l_scale_*linear;

    vel_pub_.publish(vel);    


  return;
}
*/
#include "ros/ros.h"
#include "geometry_msgs/Twist.h"
#include "turtlesim/TeleportAbsolute.h"

/*
int main(int argc, char *argv[]) {
  ros::init(argc, argv, "move_turtlesim");

  ros::NodeHandle nh;
  ros::Publisher cmd_vel_pub = nh.advertise<geometry_msgs::Twist>("/turtle1/cmd_vel", 10);

  ros::Duration(1.0).sleep();

  geometry_msgs::Twist msg;
  msg.linear.x = 1.0;
  cmd_vel_pub.publish(msg);

  ros::Duration(1.0).sleep();

  msg.linear.x = 0.0;
  msg.angular.z = 1.0;
  cmd_vel_pub.publish(msg);

  ros::Duration(1.0).sleep();

  ros::ServiceClient client = nh.serviceClient<turtlesim::TeleportAbsolute>("/turtle1/teleport_absolute");

  ros::Duration(1.0).sleep();

  turtlesim::TeleportAbsolute srv;
  srv.request.x = 1.0;
  srv.request.y = 10.0;
  client.call(srv);

  ros::spin();

  return 0;
}
*/