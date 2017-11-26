#include "includes.h"

int x = 0;
int y = 0;
char pch = '&';
int health = 10;

int getX(){
	return x;
}
void setX(int newX){
	x = newX;
}

int getY(){
	return y;
}
void setY(int newY){
	y = newY;
}

char getPCh(){
	return pch;
}


int getHealth(){
	return health;
}
void setHealth(int newHealth){
	health = newHealth;
}