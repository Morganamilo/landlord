#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#include <unistd.h>
#include <time.h>
#include "stuff.h"
#include "puzzles.h"
char name[21] = "User";
int yen = 0;
int health = 10;
int map = 1;
int sp = 0; // sword power -- starts as 0 as character has no weapon
int armour = 0; // protection from enemies/other attacks
int inventory[20];
bool hsl = false; // has Settlement license
// ITEMS = { SWORD_STONE = 1, SWORD_IRON = 2, EXPLOSIVE = 3, SETTLEMENT_LICENSE = 4};
bool mc1 = false;
bool mc2 = false;
bool ul1 = false;
bool bf_f1 = false;
void psb(){ // Print Stats Bar
	printf("%s :\n  Yen: %i  Health: %i  Attack: %i  Armour: %i\n", name, yen, health, sp, armour);
	if(iaco(inventory, 1)){
		printf("\n\nHAS ITEM IN INVENT\n\n");
	}
}
void remap(){
	printf("\n");
	switch(map){
		case 1:
			if(ul1){
			printf("////////////////  .  ///////////////////\n"); // unformatted tab to make it clear
			}else{
			printf("////////////////  ?  ///////////////////\n"); // unformatted tab to make it clear
			}
			printf("/   Pub          (3)                   /\n");
			printf("/========         .         Factory    /\n");
			printf("/#  (1) #..........         ========   /\n");
			printf("/========         ..........#  (2) #   /\n");
			printf("/                 .         ========   /\n");
			printf("/                 .                    /\n");
			printf("////////////////  @  ///////////////////\n");
			break;
		case 2:
			printf("//////////////// (4) ///////////////////\n");
			printf("/   Hospital      .                    /\n");
			printf("/   ========      .                    /\n");
			printf("/   #  (2) #      ...................(6)\n");
			printf("/   ========      .          ..        /\n");
			printf("/     ..          .       ========     /\n");
			printf("(3)................       #  (5) #     /\n");
			printf("/                 .       ========     /\n");
			printf("/                 .         Shop       /\n");
			printf("//////////////// (1) ///////////////////\n");
			break;
		default:
			printf("\n\nINVALID MAP RENDER OPTION -- EXITING\n\n");
			exit(-1);
	}
}
int si = 0;
void play(){
	// starting part
	if(! si){
		speech("Landlord", "Hello and welcome to sakura village! I am the landlord. Of the world...");
		speech("Landlord", "You may want to live here. You may not, But it does cost money!");
		speech("Landlord", "It only costs 8000 yen for a small house with basic living needs.");
		speech("Landlord", "You can easily go to the villagers and do jobs for them to get yen.");
	}
	speech("Landlord", "Oh and what is your name?");
	printf("\n> ");
	scanf(" %[^\n]%*c", &name);
	char outte1[81];
	sprintf(outte1, "Nice name! Now off you go %s", name);
	speech("Landlord", outte1);
	speech("Friend", "Ye let\'s go!");
	// data to make game better
	int ta_f1 = 0;
	// main game loop
	while(true){
		switch(map){
			case 1:
				stcl();
				psb();
				remap();
				printf("\n\nChose a number to go there\n>> ");
				int opt1;
				scanf("%i", &opt1);
				char np; // removes skipping
				scanf("%c", &np); // removes skipping
				switch(opt1){
					case 1:
						speech("Pub Owner", "Oh hello!");
						while(true){
							bool se = false; // should exit
							if(mc1){
								speech("Pub Owner", "I am so thankful of what you did!");
								se = true; break;
							}
							speech("Pub Owner", "Uh... Can you do a job for me?");
							printf("\n\n[y/n]> ");
							char yon;
							scanf("%c", &yon);
							switch(yon){
								case 'y':
									speech("Pub Owner", "AH! Brilliant");
									speech("Pub Owner", "All you have to do is: when a rat appears, type in it\'s id and click enter");
									int suc; // success
									suc = puzzle(1);
									stcl();
									se = true;
									switch(suc){
										case 0:
											speech("Pub Owner", "Oh sorry you didn\'t do enough to earn anything");
											break;
										case 1:
											speech("Pub Owner", "Good job! I\'ll give you 500 yen");
											yen += 500;
											gainanim("You Gained 500 yen!");
											speech("Pub Owner", "Goodbye sir");
											mc1 = true;
											break;
										case 2:
											speech("Pub Owner", "Amazing! You did very very well. I will give you 1000 yen for that!");
											yen += 1000;
											gainanim("You gained 1000 yen!");
											speech("Pub Owner", "Goodbye sir");
											mc1 = true;
											break;
									}
									break;
								case 'n':
									speech("Pub Owner", "Oh I\'m sad to hear that. GoodBye");
									se = true;
									break;
								default:
									speech("Pub Owner", "I don\'t understand what you just said. Sorry");
									break;
							}
							if(se){
								break;
							}
						}
						break;
					case 2:
						if(mc2){
							speech("Factory Owner", "Thanks to you, we are back in business");
							break;
						}
						if(bf_f1){
							speech("Factory Owner", "Get out of here!");
							break;
						}
						speech("Factory Owner", "Uh... Dis ain\'t working... Ain\'t working");
						speech("Factory Owner", "Oh kiddo. You shouldn\'t be in here. The machinery is very dangerous");
						speech("Factory Owner", "Well it is when it is working");
						bool se = false; // should exit
						while(true){
							if(se){break;}
							speech("Factory Owner", "Do you know much about mechanics?");
							printf("\n\n[y/n]> ");
							char opt7;
							scanf("%c", &opt7);
							printf("\n\nPAST opt7 INPUT\n\n");
							switch(opt7){
								case 'y':
									speech("Factory Owner", "Excellent.");
									bool se2 = false;
									while(true){
										if(se2){break;}
										speech("Factory Owner", "Can you do a job for me?");
										printf("\n\n[y/n]> ");
										char np5;
										scanf("%c", &np5);
										char opt8 = 'n';
										scanf("%c", &opt8);
										switch(opt8){
											case 'y':
												speech("Factory Owner", "Oh thank you, you are a true gentlemen.");
												speech("Factory Owner", "When a water flow comes through a pipe");
												speech("Factory Owner", "Add the number of pipe it is on to the output pipe number!");
												sleep(2);
												speech("Factory Owner", "Then type the result in and click enter!");
												speech("Factory Owner", "Simple.");
												int suc;
												suc = puzzle(2);
												switch(suc){
													case 0:
														se2 = true;
														se = true;
														speech("Factory Owner", "GRR... You know nothing about mechanics! You lied to me and broke it all");
														bf_f1 = true;
														break;
													case 1:
														mc2 = true;
														se2 = true;
														se = true;
														speech("Factory Owner", "Ah thank you. You did an okay job. Here is 650 yen.");
														yen+=650;
														gainanim("You gained 650 yen");
														speech("Factory Owner", "Goodbye");
														break;
													case 2:
														mc2 = true;
														se2 = true;
														se = true;
														speech("Factory Owner", "WOW! Amazing work kid. Here, have 1100 yen.");
														yen+=1100;
														gainanim("You gained 1100 yen");
														speech("Factory Owner", "Goodbye");
														break;
												}
												char np7;
												scanf("%c", &np7);
												break;
											case 'n':
												speech("Factory Owner", "Oh that\'s unfortunate. Well bye");
												se2 = true;
												se = true;
												break;
											default:
												speech("Factory Owner", "Sorry I don't understand what you just said");
												break;
										}
									}
									break;
								case 'n':
									speech("Factory Owner", "Oh okay it doesn\'t matter then. I would prefer you not to get hurt");
									se = true;
									break;
								default:
									speech("Factory Owner", "I don't understand what you just said");
									break;
								
							}
						}
						break;
					case 3:
						speech("Gate Guard", "You want to go through here?");
						printf("\n\n[y/n]> ");
						bool wtp = false; // wants to pass
						char opt2;
						scanf("%c", &opt2);
						switch(opt2){
							case 'y':
								wtp = true;
								break;
							case 'n':
								wtp = false;
								speech("Gate Guard", "I thought so... Kid");
								break;
							default:
								speech("Gate Guard","I don\'t understand jiberish... Kid");
								break;
						}
						if(wtp){
							if(ul1){
								map = 2;
							}else{
								speech("Gate Guard", "Hey! You haven\'t paid...");
								speech("Gate Guard", "It only costs 175 yen to open this up for lifetime access. Deal?");
								printf("\n\n[y/n]> ");
								char opt3;
								char np2;
								scanf("%c", &np2);
								scanf("%c", &opt3);
								switch(opt3){
									case 'y':
										if(yen >= 175){
											printf("\n\nYen:   %i -> &i", yen, (yen-175)); // display transaction
											yen-=175;
											sleep(1);
											ul1 = true;
											speech("Gate Guard", "Now you have paid, you can come through here at anytime");
											map = 2;
										}else{
											speech("Gate Guard", "You little scumbag! You don\'t have enough money!");
										}
										break;
									case 'n':
										speech("Gate Guard", "Alright, well don\'t waste my time.");
										break;
									default:
										speech("Gate Guard", "I don\'t understand jiberish... Kid");
										break;
								}
							}
						}
						break;
					default:
						printf("\nInvalid option!\n");
						sleep(1);
						break;
				}
				break;
			case 2:
				stcl();
				psb();
				remap();
				printf("\n\nChose a number to go there\n>> ");
				int opt4;
				scanf("%i", &opt4);
				switch(opt4){
					case 1:
						speech("Gate Guard", "You want to go through here?");
						printf("\n\n[y/n]> ");
						char np2;
						scanf("%c", &np2);
						char opt6;
						scanf("%c", &opt6);
						switch(opt6){
							case 'y':
								map = 1;
								break;
							case 'n':
								speech("Gate Guard", "I thought so... Kid");
								break;
							default:
								speech("Gate Guard", "I don\'t understand jiberish... Kid");
								break;
						}
						break;
					case 2:
						break;
					case 3:
						if(sp == 0){
							switch(ta_f1){
								case 0:
									speech("Forester", "Ey! You ain\'t coming through here without any line of defence!");
									speech("Forester", "There are scary. VERY SCARY things through here. I dont want you dead");
									break;
								case 1:
									speech("Forester", "Like I said. Your NOT coming through!!!");
									break;
								case 2:
									speech("Forester", "Your not going past here without defence!");
									break;
								case 3:
									speech("Forester", "I honestly recommend you get a sword if you want any chance of going in there.");
									break;
								case 4:
									speech("Forester", "I dont want you getting hurt now get a sword!");
									break;
							}
							ta_f1++;
							if(ta_f1 > 4){ta_f1 = 4;}
							break;
						}else{
							speech("Forester", "Ey! You ain't coming thro.....");
							speech("Forester", "I see you got yourself SOME defence. Go on then...");
							speech("Forester", "*sigh*...");
							map = 3;
						}
					case 4:
						break;
					case 5:
						stcl();
						bool se = false;
						speech("Shop keeper", "Welcome");
						while(true){
							if(se){break;}
							stcl();
							printf("\n\n");
							printf(" 0 to exit\n");
							printf("\nId  Name                Price\n\n");
							printf("1) Stone Sword          400 yen\n");
							printf("2) Settlement license   8000 yen\n");
							int opt9;
							printf("\n>> ");
							scanf("%i", &opt9);
							printf("\n\n");
							switch(opt9){
								case 0:
									se = true;
									break;
								case 1:
									if(! iaco(inventory, 1)){
										if(yen >= 400){
											bool se11 = false;
											while(true){
												if(se11){break;}
												speech("Shop Keeper", "Are you sure you want to lose 400 yen for a stone sword?");
												printf("\n\n[y/n]> ");
												char np42;
												scanf("%c", &np42);
												char opt10;
												scanf("%c", &opt10);
												switch(opt10){
													case 'y':
														yen-=400;
														inventory[(sizeof(inventory) / sizeof(inventory[0]) - 1)] = 1;
														speech("Shop Keeper", "Thank you");
														se11 = true;
														break;
													case 'n':
														break;
													default:
														speech("Shop Keeper", "I don\'t understand what you just said.");
												}
											}
										}else{
											speech("Shop Keeper", "You don\'t have 400 yen to buy that, sorry.");
										}
									}else{
										speech("Shop Keeper", "You already have that");
									}
									break;
								case 2:
									break;
							}
						}
						speech("Shop Keeper", "Goodbye");
						break;
					default:
						printf("\nInvalid option!\n");
						sleep(1);
						break;
				}
				break;
		}
	}
}
bool cfte = false; // cheats for testing enabled? -- disabled for main play, enable for testing stuff without wasting time
void settings(){
	stcl();
	while(true){
		stcl();
		printf("0 to exit\n\n");
		printf("1) Comming soon\n");
		printf("2) FAKE OPTION\n");
		printf("3) Animate Text : %i\n", ante);
		if(cfte){
			printf("\n       Cheats\n");
			printf("101) Get 1000 yen\n");
			printf("102) Set start map\n");
			printf("103) Skip intro: %i", si);
		}
		printf("\n\n>>> ");
		int opt5;
		scanf("%i", &opt5);
		printf("\n\n");
		switch(opt5){
			case 0:
				return;
			case 2:
				while(true){
					printf("FAKE OPTION IS FAKE! - YOU SHOULD NOT HAVE CHOSEN IT\n");
				}
			case 3:
				if(ante == 1){
					ante = 0;
				}else{
					ante = 1;
				}
				break;
			
			case 101:
				if(cfte){
					yen+=1000;
					printf("\n\nYou now have %i yen\n\n", yen);
					sleep(1);
				}
				break;
			case 102:
				if(cfte){
					printf("New map id\n>> ");
					int nsm; // new start map
					scanf("%i", &nsm);
					map = nsm;
				}
				break;
			case 103:
				if(cfte){
					if(si){
						si = false;
					}else{
						si = true;
					}
				}
				break;
			default:
				printf("\n\nThat is an invalid option!!!\n\n");
				sleep(1);
				break;
		}
	}
}
