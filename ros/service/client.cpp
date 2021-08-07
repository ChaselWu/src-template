#include <cstdlib>
#include "ros/ros.h"

//include your own SRV.h
#include "beginner_tutorial/my_srv.h"


int main(int argc, char **argv)
{

    //"" is the name of this node
    ros::init(argc, argv, "client");

    ros::NodeHandle n;
    
    //wait till finding service ""
    ros::service::waitForService("/SERVICENAME");
    
    
    //create a client
    //<> is the service type
    //"" is the name of the service this client sends requsts to
    ros::ServiceClient client = n.serviceClient<beginner_tutorial::my_srv>("/SERVICENAME");
    
    
    beginner_tutorial::my_srv srv;
    srv.request.req1 = "this is an example";
    srv.request.req2 = 42;
    srv.request.req3 = -42;
    
    //use call, a member function of ros::ServiceClient, to send requests and get responses
    client.call(srv);
    ROS_INFO("successfully get a response:[%s]",srv.response.res1.c_str());
    /*if (client.call(srv))
    {
        ROS_INFO("successfully get a response:[%s]",srv.response.res1.c_str());
    }
    else
    {
        ROS_ERROR("Failed to call service /SERVICENAME");
        return 1;
    }*/

    return 0;
}
