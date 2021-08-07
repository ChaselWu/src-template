#include "ros/ros.h"
#include "std_msgs/String.h"

/*callback function running when receiving a message
  the prameter is a poiner of your message
*/
void chatterCallback(const std_msgs::String::ConstPtr& msg) {
  // printf
  ROS_INFO("I heard: [%s]", msg->data.c_str());

  // someting else
}

int main(int argc, char** argv) {
  // init the subscrber and name it ""
  ros::init(argc, argv, "listener");

  ros::NodeHandle n;

  /*create a subsciber
        "" is the name of topic
        1000 is the size of the message queue
        the third parameter is the callback function
  */
  ros::Subscriber sub = n.subscribe("chatter", 1000, chatterCallback);

  /**
   * ros::spin() will enter a loop, pumping callbacks.  With this version, all
   * callbacks will be called from within this thread (the main one).
   * ros::spin() will exit when Ctrl-C is pressed, or the node is shutdown by
   * the master.
   */
  ros::spin();

  return 0;
}
