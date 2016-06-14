#include <stdio.h>
#include <termios.h>

int main(int argc,char** argv)
{
	struct termios ts;
    tcgetattr(0,&ts);
    printf("input speed %d \n",cfgetispeed(&ts));
    printf("ouput speed %d \n",cfgetospeed(&ts));
	return 0;
}
