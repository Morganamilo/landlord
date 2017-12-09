#include "includes.h"
#include "display.h"
#include "mapping.h"

int isNum(char c){
	int ascii = (int) c;
	ascii -= (int) '0';
	if(ascii >= 0 && ascii <= 9){
		return 1;
	}else{
		return 0;
	}
}

/*
 * I know this is the shitty way to do it,
 * but I did it this way anyway, get over it.
*/
int isBE(char c){
	if(c == '{')
		return 1;
	if(c == '}')
		return 1;
	if(c == '~')
		return 1;
	if(c == '|')
		return 1;
	
	return 0;
}

int los(char str[]){ // Length of string
	char*s = str;
	int i = 0;
	while(*s++) i++;
	return i;
}

void speech(char npc[], char message[50]){	// Maximum of 50 characters for the message
	printf("\t%s:\n", npc);
	printf("\n##################################################\n\n"); // 50 characters across
	
	printf("##################################################\n"); // same here
	
	topDisplay();
	int i;
	for(i = 0; i < getHeight()+3; i++)
		printf("\n");
	
	for( i = 0; i < los(message); i++){
		printf("%c", message[i]);
		fflush(stdout);
		usleep(50000);
	}
	
	getchar(); // Wait until the user presses a key to continue
	
	clearDisplay();
	topDisplay();
	renderBuffer();
	
}