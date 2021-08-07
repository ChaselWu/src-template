#include "ros/ros.h"
#include "beginner_tutorial/my_srv.h"


//callback function of service, input req and output res
bool callback(beginner_tutorial::my_srv::Request  &req,
         beginner_tutorial::my_srv::Response &res)
{
  res.res1 = req.req1;
  res.res2 = req.req2 + 0.1;
  ROS_INFO("request: %s, %d, %ld", req.req1.c_str(), req.req2, req.req3);
  ROS_INFO("sending back response: [%s  %f]", res.res1.c_str(), res.res2);
  return true;
}

int main(int argc, char **argv)
{
  //"" is the name of this node
  ros::init(argc, argv, "server");
  
  ros::NodeHandle n;

  //"" is the name of the service
  ros::ServiceServer service = n.advertiseService("/SERVICENAME", callback);
  
  ROS_INFO("Ready to do some services.");
  
  ros::spinOnce();

  return 0;
}
