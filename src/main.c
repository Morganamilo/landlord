#include "includes.h"
#include "display.h"
#include "mapping.h"
#include "player.h"
#include "game.h"

int on = 1;

int main(){
	initDisplay();
	clearDisplay();
	while(on){
		topDisplay();
		printf("\n\tWelcome to Landlord!\n");
		printf("=============================\n");
		printf("A free open-source text-based\n");
		printf("puzzle and tactic game\n\n");
		printf("=============================\n\n\n");
		printf("[0] Exit\n");
		printf("[1] Start game\n");
		printf("[2] Coming Soon\n");
		printf("\n\n>> ");
		fflush(stdout);
		char c = getchar();
		switch(c){
			case '0':
				on = 0;
				break;
			case '1':
				startGame();
				break;
			case '2':
				break;
		}
	}
	clearDisplay();
	topDisplay();
	printf("\nGoodbye!\n\n");
	return 0;
}