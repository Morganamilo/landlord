#include "includes.h"
#include "display.h"

struct termios oldt, newt;

void initDisplay(){
	atexit(stopDisplay);
	
	tcgetattr(STDIN_FILENO, &oldt);
	newt = oldt;
	
	newt.c_lflag &= ~(ICANON);
	newt.c_lflag |= ~(ECHO);
	
	tcsetattr(STDIN_FILENO, TCSANOW, &newt);
}
void stopDisplay(){
	tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
}

void clearDisplay(){
	printf("\x1B[2J");
	fflush(stdout);
}
void topDisplay(){
	printf("\x1B[H");
	fflush(stdout);
}
