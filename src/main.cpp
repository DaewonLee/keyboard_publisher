#include "ros/ros.h"
#include "std_msgs/Char.h"
#include <termios.h>

int getch(void)
{
    struct termios oldattr, newattr;
    int ch;
    tcgetattr( STDIN_FILENO, &oldattr );
    newattr = oldattr;
    newattr.c_lflag &= ~( ICANON | ECHO );
    tcsetattr( STDIN_FILENO, TCSANOW, &newattr );
    ch = getchar();
    tcsetattr( STDIN_FILENO, TCSANOW, &oldattr );
    return ch;
}

int main(int argc, char **argv)
{
	ros::init(argc, argv, "keyboard_publisher");
	ros::NodeHandle nh;
	ros::Publisher key_pub;
	key_pub = nh.advertise<std_msgs::Char >("/key_input",1);
	std_msgs::Char command_key;

    while (ros::ok()) {
		ros::spinOnce();
        command_key.data = getch();
        key_pub.publish(command_key);
        printf("%c\n",command_key.data);
		if(isspace(command_key.data))
		{
			printf("Bye!\n");
			break;
		}
	}
	return 0;
}
