#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#include <unistd.h>
int ante = 1; // ante = animate text -- can be toggled in settings
int los(char *s){
	int i = 0;
	while(*s++) i++;
	return i;
}
bool iaco(int array[256], int integer){
	int *arry;
	int noe = sizeof(arry) / sizeof(arry[0]) - 1;
	int i;
	for(i = 0; i < noe; i++){
		if(array[i] == integer){return true;}
	}
	return false;
}
void stcl(){
	#ifdef __WIN32
		system("cls");
	#else
		system("clear");
	#endif
}
void speech(char cn[15], char speech[81]){
	stcl();
	int a;
	char *text2 = speech;
	int noe = los(text2)+1;
	if(noe > 80){
		printf("\n\nError:\n    Line 15 method\n    Out of bounds: more than 81");
		exit(-1);
	}
	if(ante == 1){
		for(a = 0; a < noe; a++){
			stcl();
			printf("\n   %s:\n========================================\n", cn);
			int b;
			for(b = 0; b < a; b++){
				char cc = speech[b];
				if(b == 40){
					printf("\n%c", cc);
				}else{
					printf("%c", cc);
				}
			}
			if(noe < 40){
				printf("\n");
			}else{
				if(a <= 40){
					printf("\n");
				}
			}
			printf("\n========================================\n");
			usleep(50000);
		}
		usleep(800000);
		return;
	}else{
		printf("\n   %s:\n========================================\n", cn);
		int b;
		for(b = 0; b < noe; b++){
			char cc = speech[b];
			if(b == 40){
				printf("\n%c", cc);
			}else{
				printf("%c", cc);
			}
		}
		if(noe < 40){
			printf("\n");
		}else{
			if(a <= 40){
				printf("\n");
			}
		}
	printf("\n========================================\n");
	usleep(2000000);
	}
}
void gainanim(char message[40]){
	stcl();
	int j;
	bool tmp1 = true; // boolean of temporary 1 which stores which congratulations banner it shows
	for(j = 0; j<10; j++){
		stcl();
		if(tmp1){
			printf("\n\n[][][][][][][][][][]\n");
			printf("  CONGRATULATIONS\n");
			printf("[][][][][][][][][][]\n\n");
		}else{
			printf("\n\n        []          \n");
			printf("       ATU\n");
			printf("        []          \n\n");
		}
		printf("\n %s", message);
		usleep(300000);
		if(tmp1){
			tmp1 = false;
		}else{
			tmp1 = true;
		}
	}
	stcl();
}
