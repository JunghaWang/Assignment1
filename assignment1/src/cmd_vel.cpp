#include "ros/ros.h"
#include "std_msgs/Float64.h"
#include "std_msgs/String.h"
#include "assignment1/msg.h"
#include <iostream>
#include <signal.h>


int main(int argc, char **argv)
{
	// ROS node with a give name "cmd_vel"
	ros::init(argc, argv, "cmd_vel");
	// a handle to this process's node.
	ros::NodeHandle n;

	// The advertise() function is how you tell ROS that you want to publish on a given topic name.
	ros::Publisher cmd_vel = n.advertise<Assignment1::msg>("cmd_input", 1);

	// A ros::Rate object allows you to specify a frequency that you would like to loop at. It will keep track of how long it has been since the last call to Rate::sleep(), and sleep for the correct amount of time.
	ros::Rate hz(10);

	// Declare a message variable.
	Assignment1::msg msg;
	/**
	 * circularMotion.msg
		* float64 radius
		* float64 velocity
		* string direction
	 */
	
	while(ros::ok())
	{
		// Get keyboard input
		printf("\n[INFO] Put Your Command\n");
		
		std::cout << "Radius: ";
		std::cin >> msg.radius;
		if(std::string(typeid(msg.radius).name()) != "d"){
			std::cout << "Exit..." << std::endl;
			break;
		}

		std::cout << "Velocity: ";
		std::cin >> msg.velocity;
		if(std::string(typeid(msg.velocity).name()) != "d"){
			std::cout << "Exit..." << std::endl;
			break;
		}

		std::cout << "Direction(CCW or CW): ";
		std::cin >> msg.direction;
		if((msg.direction == "CW") || (msg.direction == "CCW"));
		else{
			std::cout << "Exit..." << std::endl;
			break;
		}

		printf("\nPublishing...\n");

		// Publish our custom message
		custom_msg_pub.publish(msg);
		hz.sleep();
	}
	return 0;
}