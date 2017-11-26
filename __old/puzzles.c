#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#include <unistd.h>
#include <time.h>
#include "stuff.h"
int ratpuz(){
	stcl();
	srand(time(NULL));
	int suced = 0; // int succeeded
	int max = 10; // max needed
	int tot = 0; // total
	while(tot < (max)){
		sleep(2);
		stcl();
		int id = rand() % 20; // random from 0 to 19
		int x = rand() % 10; // x axis from 0 to 9
		int y = rand() % 12; // y axis from 0 to 11
		int bigy = 14;
		int xi;
		int yi;
		int xj;
		// render
		for(yi = 0; yi < y; yi++){printf("\n"); }
		for(xi = 0; xi < x; xi++){printf(" ");  }
		printf("[%i]\n", id);
		for(xj = 0; xj < x; xj++){printf(" ");  }
		printf("~@~\n");
		for(; yi < bigy; yi++){  printf("\n");  }
		printf("\n>> ");
		// inputing it
		int st = time(NULL); // start time is current second
		int inp; // input integer
		scanf("%i", &inp);
		int et = time(NULL); // end time is time after input in seconds
		if(et > (st + 2)){
			printf("\n\nThe rat ran off -- you were too slow\n");
			usleep(800000);
		}else{
			if(inp == id){
				printf("\n\nYou caught the rat!\n");
				suced++;
			}else{
				printf("\n\nWrong id!\n\n");
				usleep(800000);
			}
		}
		tot++;
	}
	if(suced >= (max-1)){
		return 2;
	}
	if(suced > 6){
		return 1;
	}
	return 0;
}
int pipepuz(){
	stcl();
	srand(time(NULL)); // set random seed to current second
	int suced = 0; // succeeded
	int tot = 0; // total
	int max = 15; // maximum
	int lai = -1; // last ipi
	//countdown
	stcl();
	printf("\n\n   3   \n\n");
	sleep(1);
	stcl();
	printf("\n\n   2   \n\n");
	sleep(1);
	stcl();
	printf("\n\n   1   \n\n");
	sleep(1);
	//main loop
	while(tot < (max)){
		sleep(2);
		stcl();
		int ipi = rand() % 6; // input pipe is random between 0 and 5
		int opi = rand() % 5; // output pipe is random between 0 and 4
		while(ipi == lai){
			ipi = rand() % 6;
		}
		// render
		printf("\n");
		printf("=========\n");
		if(ipi == 0){
		printf("\\/\\/\\/ [0]\n"); // unformatted tab to make it clear
		}else{
		printf("       [0]\n"); // unformatted tab to make it clear
		}
		printf("=========\n");
		printf("=========\n");
		if(ipi == 1){
		printf("\\/\\/\\/ [1]\n");
		}else{
		printf("       [1]\n");
		}
		printf("=========\n");
		printf("=========\n");
		if(ipi == 2){
		printf("\\/\\/\\/ [2]\n");
		}else{
		printf("       [2]\n");
		}
		printf("=========\n");
		printf("=========         ===\n");
		if(ipi == 3){
		printf("\\/\\/\\/ [3]         [%i]\n", opi);
		}else{
		printf("       [3]         [%i]\n", opi);
		}
		printf("=========         ===\n");
		printf("=========\n");
		if(ipi == 4){
		printf("\\/\\/\\/ [4]\n");
		}else{
		printf("       [4]\n");
		}
		printf("=========\n");
		printf("=========\n");
		if(ipi == 5){
		printf("\\/\\/\\/ [5]\n");
		}else{
		printf("       [5]\n");
		}
		printf("=========\n");
		printf("\n\n>>> ");
		int inp;
		int st = time(NULL);
		scanf("%i", &inp);
		printf("\n\n");
		int et = time(NULL);
		if(et > (st + 3)){
			printf("You were too slow. Damage was caused\n");
		}else{
			if(inp == (ipi + opi)){
				printf("The water was saved\n");
				suced++;
			}else{
				printf("Wrong number dumbo! Damage was caused\n");
			}
		}
		tot++;
		lai = ipi;
	}
	// scoring
	if(suced == tot){
		return 2;
	}
	if(suced > (tot - 3)){
		return 1;
	}
	return 0;
}
int puzzle(int level){ // 0 = failed   1 = okay    2 = excellent
	int exco;
	switch(level){
		case 1:
			exco = ratpuz();
			break;
		case 2:
			exco = pipepuz();
			break;
	}
	return exco;
}
