#include "includes.h"
#include "mapping.h"
#include "player.h"
#include "util.h"

char mapBuffer[1024];

void clearBuffer(){
	int i;
	for(i = 0; i < 1024; i++){
		mapBuffer[i] = ' ';
	}
}
void writeBuffer(char map[1024]){
	int i;
	for(i = 0; i < 1024; i++){
		if(! map[i]) break;
		mapBuffer[i] = map[i];
	}
}
char getBufferCharacter(int mx, int my){
	if(mx > getWidth()) return '\t'; // Tabs are never used, so return it if so
	if(my > getHeight()) return '\t'; // Same here
	
	int i;
	int cx = 0;
	int cy = 0;
	for(i = 0; i < 1024; i++){
		if(mapBuffer[i] == '\n'){
			cx = 0;
			cy++;
			continue;
		}
		if(cx == mx && cy == my){
			return mapBuffer[i];
		}
		cx++;
	}
}

void renderBuffer(){
	int px = getX();
	int py = getY();
	int i;
	int cx = 0;	// Current x
	int cy = 0;	// Current y
	for(i = 0; i < 1024; i++){
		if(mapBuffer[i] == '\n'){
			cx = 0;
			cy++;
			printf("\n");
			continue;
		}
		if(! mapBuffer[i]) break;
		if(cx == px && cy == py){
			printf("\e[38;5;3m%c\e[0m", getPCh());
		}else{
			if(isNum(mapBuffer[i])){
				printf(".");
			}else if(isBE(mapBuffer[i])){
				printf("^");
			}else{
				printf("%c", mapBuffer[i]);
			}
		}
		cx++;
	}
	fflush(stdout);
}


int getHeight(){
	int height = 0;
	int i = 0;
	while(i < 1024){
		if(mapBuffer[i++] == '\n'){
			height++;
		}
	}
	return height;
}
int getWidth(){ // For this to work properly all the lines must be the exact same lengh
		// For weirdly shaped maps, just fill missing gaps with spaces
	int width = 0;
	int i = 0;
	while(mapBuffer[i++] != '\n') width++;
	return width;
}

void loadMap(int mapId){
	switch(mapId){
		case 1:
			writeBuffer(	"############1#############\n"
					"#           .            #\n"
					"#           .            #\n"
					"#           . #Factory#  #\n"
					"#  #Pub#    . ###(})###  #\n"
					"#  #({)#    .     .      #\n"
					"#    .      .     .      #\n"
					"#    ..............      #\n"
					"#            .           #\n"
					"#            .           #\n"
					"#############0############\n");
			break;
		case 2:
			writeBuffer(	"##################4#######\n"
					"#                 .      #\n"
					"#                 .      #\n"
					"#                 .      #\n"
					"#  #Shop#         .      #\n"
					"#  ##({)#   .............3\n"
					"#     .     .            #\n"
					"2............            #\n"
					"#           .            #\n"
					"#           .            #\n"
					"############1#############\n");
			break;
	}
}