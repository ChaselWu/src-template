#include <sstream>

#include "ros/ros.h"
#include "std_msgs/String.h"


int main(int argc, char **argv) {
  //init this node: please name it
  ros::init(argc, argv, "publisher_name");

  //creat a nodehandle
  ros::NodeHandle n;

  /*creat a publisher 
  <> is the type of the message 
  "" is the name of the topic published
  1000 is the length of the message deque  
  */
  ros::Publisher chatter_pub = n.advertise<std_msgs::String>("chatter", 1000);

  //set the loop rate(easy to understand when seeing the while and sleep)
  ros::Rate loop_rate(10);

  //count the loop
  int count = 0;
  
  //send message circularly
  while (ros::ok()) {
    
    //a message example
    std_msgs::String msg;

    //std stream
    std::stringstream ss;
    ss << "hello world " << count;
    msg.data = ss.str();
    
    //like printf
    ROS_INFO("%s", msg.data.c_str());

    //send message to topic
    chatter_pub.publish(msg);

    //we need spinOnce when receiving callbacks
    ros::spinOnce();

    loop_rate.sleep();
    ++count;
  }

  return 0;
}
