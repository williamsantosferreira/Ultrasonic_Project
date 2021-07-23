#include <iostream>
#include "ros/ros.h"
#include "std_msgs/String.h"
#include "serial/serial.h"


int main(int argc,char **argv){
	std_msgs::String msg;

        serial::Serial *porta_serial;

	porta_serial = new serial::Serial("/dev/ttyACM0",9600,serial::Timeout::simpleTimeout(1000));

	ros::init(argc,argv,"teste");

	ros::NodeHandle n;

	ros::Publisher pub = n.advertise<std_msgs::String>("t",1000);

	ros::Rate loop_rate(1);

	while(ros::ok()){
		ROS_INFO("teste");
		porta_serial->write("Teste\r");
		loop_rate.sleep();		
	}	
return 0;
}

