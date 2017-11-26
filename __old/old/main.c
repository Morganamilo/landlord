#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#include <unistd.h>
#include "stuff.h"
#include "game.h"

#define DEVCOL  "\x1B[33m"
int main(){
	if(cfte){
		printf("%s", DEVCOL);
	}
	bool se = false; // se = should exit
	while(true){
		stcl();
		printf("\n\n");
		printf("===========================\n");
		printf("#  Welcome to landlord!   #\n"); // i could really put this on one line but neh, cant be asked
		printf("# A free open-source text #\n"); // so dont ask me to :P
		printf("# based puzzle and tactic #\n");
		printf("#         game!           #\n");
		printf("===========================\n");
		printf("\n\n1) Start game\n2) Settings\n3) Exit\n\n>>> ");
		int inp;
		scanf("%i", &inp);
		switch(inp){
			case 1:
				play();
				break;
			case 2:
				settings();
				break;
			case 3:
				se = true; 
				break;
		}
		if(se){
			break;
		}
	}
	stcl();
	printf("\x1B[0m \n\n[ Goodbye! ]\n\n");
	return 0;
}
