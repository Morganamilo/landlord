#include "includes.h"
#include "display.h"
#include "mapping.h"
#include "player.h"
#include "game.h"
#include "util.h"

int running = 1;
int map = 1;

void startGame(){
	running = 1;
	map = 1;
	clearDisplay();
	loadMap(map);
	setX(13);
	setY(9);
	// Main game loop
	while(running){
		topDisplay();
		renderBuffer();
		char c = getchar();
		
		int movementCancelled = 0;
		int resultY = getY();
		int resultX = getX();
		char cap;
		
		switch(c){
			case 'q':
				askQuit();
				break;
			
			case 'w':
				--resultY;
				break;
			case 's':
				++resultY;
				break;
			case 'a':
				--resultX;
				break;
			case 'd':
				++resultX;
				break;
		}
		cap = getBufferCharacter(resultX, resultY);
		if(map == 1){
			//
			if(cap == '0'){
				movementCancelled = 1;
				askQuit();
			}
			if(cap == '1'){
				movementCancelled = 1;
				map = 2;
				loadMap(map);
				setY(9);
			}
			
			
			
		}else if(map == 2){
			if(cap == '1'){
				movementCancelled = 1;
				map = 1;
				loadMap(map);
				setY(1);
			}
		}
		
		
		// Move
		if(cap == ' ' || cap == '.'){
			if(! movementCancelled){
				setX(resultX);
				setY(resultY);
			}
		}
	}
}

void askQuit(){
	printf("\nAre you sure you want to quit?\n[y/n]> ");
	fflush(stdout);
	int asking = 1;
	while(asking){
		char c2 = getchar();
		switch(c2){
			case 'y':
				running = 0;
				asking = 0;
				break;
			case 'n':
				asking = 0;
				break;
			default:
				break;
		}
	}
	clearDisplay();
	topDisplay();
}