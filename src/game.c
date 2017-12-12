#include "includes.h"
#include "display.h"
#include "mapping.h"
#include "player.h"
#include "game.h"
#include "util.h"

int running = 1;
int map = 10;

void startGame(){
	running = 1;
	map = 10;
	clearDisplay();
	topDisplay();
	loadMap(map);
	px = 13;
	py = 9;
	renderBuffer();
	speech("Landlord", "Hello and welcome to Landlord!");
	speech("Landlord", "I am the landlord... of the world.");
	speech("Landlord", "The place you can start off at is Sakura village"); // Sakura is actually Japanese for "Cherry Blossom"
	speech("Landlord", "You can get money from doing jobs for villagers");
	// Main game loop
	while(running){
		topDisplay();
		renderBuffer();
		char c = getchar();
		
		int movementCancelled = 0;
		int resultY = py;
		int resultX = px;
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
		if(map == 10){
			//
			if(cap == '0'){
				movementCancelled = 1;
				askQuit();
			}
			if(cap == '1'){
				movementCancelled = 1;
				map = 20;
				loadMap(map);
				py = 9;
			}
			
			
			
		}else if(map == 20){
			if(cap == '1'){
				movementCancelled = 1;
				map = 10;
				loadMap(map);
				py = 1;
			}
		}
		
		
		// Move
		if(cap == ' ' || cap == '.'){
			if(! movementCancelled){
				px = resultX;
				py = resultY;
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
