#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<conio.h>
#include<time.h>
//#include<unistd.h>
#include<Windows.h>

void gotoxy(int x,int y){
 COORD coord = {x,y};
 SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

FILE *fp;

struct main{
	char name[100];
	int dd;
	int mm;
	int yy;
	int money;
};

struct stock{
	int lemon;
	int glass;
	int ice;
	int sugar;
	char place[100];
	char equip[100];
	char booth[100];
	char weather[100];
};

int menu(){
	int a;

	printf("Welcome to Lemonade Tycoon\n\n");
	printf("What would you like to do?\n");
	printf("1. Open new shop\n");
	printf("2. Load current shop\n");
	printf(">>>"); scanf("%d", &a); fflush(stdin);

	return a;
}

void new_(struct main player, struct stock stc){
	printf("Input your shop's name: "); gets(player.name);
	fp = fopen ("data.txt", "w");

	fprintf(fp, "%s#01#01#01#2000#10#10#10#10#little town#blender#booth", player.name);

	fclose(fp);
}

void load(struct main *player, struct stock *stc){
	fp = fopen("data.txt","r");
	if(fp==NULL){
		printf("There are no saved game");
	}
	else{
		fscanf(fp,"%[^#]#%d#%d#%d#%d#%d#%d#%d#%d#%[^#]#%[^#]#%[^#]", &player->name, &player->dd, &player->mm, &player->yy, &player->money, &stc->glass, &stc->ice, &stc->lemon, &stc->sugar, &stc->place, &stc->equip, &stc->booth);
	}
	fclose(fp);
}

void save(struct main player, struct stock stc){
	fp = fopen ("data.txt", "w");

	fprintf(fp, "%s#%d#%d#%d#%d#%d#%d#%d#%d#%s#%s#%s", player.name, player.dd, player.mm, player.yy, player.money, stc.glass, stc.ice, stc.lemon, stc.sugar, stc.place, stc.equip, stc.booth);

	fclose(fp);
}

void view(struct main player, struct stock stc){
	system("cls");
	printf("%s's shop'\n", player.name);
	printf("\n\n\n\n");
	printf("Day: %d\tMonth: %d\tYear: %d\n", player.dd, player.mm, player.yy);
	printf("\n Money: $%d\n", player.money);
	printf("Stock:\n");
	printf("\t1.Lemon: %d\n", stc.lemon);
	printf("\t2.Plastic Glass: %d\n", stc.glass);
	printf("\t3.Ice: %d\n", stc.ice);
	printf("\t4.Sugar: %d\n", stc.sugar);

	printf("\nPlace: %s", stc.place);
	printf("\nEquipment: %s", stc.equip);
	printf("\nBooth: %s\n", stc.booth);
	system("pause");
}

void buy(struct stock *stc, struct main *player){
	system("cls");
	int buy=0;
	int qty=0;
	int prc=0, rem=0;

	char d[2];
	do{

	printf("Stock:\n");
	printf("\t1.Lemon[$10]: %d\n", stc->lemon);
	printf("\t2.Plastic Glass[$10]: %d\n", stc->glass);
	printf("\t3.Ice[$5]: %d\n", stc->ice);
	printf("\t4.Sugar[$5]: %d\n", stc->sugar);
	printf ("Your money: $%d\n", player->money);
	printf("What do you want to buy? [enter the stock number] \n");
	scanf("%d", &buy); fflush(stdin);
	printf("Quantity: \n");
	scanf("%d", &qty); fflush(stdin);

	switch(buy){
		case 1: prc=qty*10;
				rem=player->money-prc;
				if (rem<0){
					printf("You don't have enough money\n");
				}
				else{
					player->money=player->money-prc;
					stc->lemon=stc->lemon+qty;
					printf("Purchase successful. Now you have %d lemons", stc->lemon);
				}
				 break;
		case 2: prc=qty*10;
				rem=player->money-prc;
				if (rem<0){
					printf("You don't have enough money\n");
				}
				else{
					player->money=player->money-prc;
					stc->glass=stc->glass+qty;
					printf("Purchase successful. Now you have %d glasses", stc->glass);
				}
				break;
		case 3: prc=qty*10;
				rem=player->money-prc;
				if (rem<0){
					printf("You don't have enough money\n");
				}
				else{
					player->money=player->money-prc;
					stc->ice=stc->ice+qty;
					printf("Purchase successful. Now you have %d ices", stc->ice);
				}
				break;
		case 4: prc=qty*10;
				rem=player->money-prc;
				if (rem<0){
					printf("You don't have enough money\n");
				}
				else{
					player->money=player->money-prc;
					stc->sugar=stc->sugar+qty;
					printf("Purchase successful. Now you have %d sugar", stc->sugar);
				}
				break;
	}

	printf("Do you want to buy anything else? [y/n] \n");
	scanf("%c", &d); fflush(stdin);

	}while(d=="y");

	system("pause");
}

void change_recipe(){
	int lemon=0, sugar=0, ice=0;

	printf("             ``..----:::---.` \n");
	printf("          `.----..`.`.-:::::::-.     \n");
	printf("        .--..``. ```.---:::::::::-`    \n");
	printf("      .-:-.`.``.``-.----:::::::::::.   \n");
	printf("     .:--``.`.....----::::::::::::::-   \n");
	printf("    -::---.---------:::::::::::::::::::. \n");
	printf("   .:-:::--------:::::::::::::::::::///- \n");
	printf("  `:--..-::::::::::::::::::::::::::///:  \n");
	printf("  -:--.--:::::::::::::::::::::::::///:`  \n");
	printf(" `:-::-:-::::::::::::::::::::::::///:.  \n");
    printf(".+-..-:::::::::::::::::::::::::////:. \n");
    printf("`::::::::::::::::::::::::::::////:-`  \n");
    printf("     .:::::::::::::::::::::////:-`  \n");
    printf("       .-::::::::::::///////:- \n");
  	printf("          `.--::::::::::--.`  \n");
	printf("Input quantity of lemon per serving: "); scanf("%d", &lemon); fflush(stdin);


	printf("                                   `..  \n");
	printf("                                 .:///` \n");
	printf("                               .:///-` \n");
	printf("                             .://:.   \n");
	printf("                          `-:/:.`  \n");
	printf("                        `-:/-` \n");
	printf("                      `-::. \n");
	printf("                    `-:-` \n");
	printf("                  `-:.   \n");
	printf("                `-:.   \n");
	printf("          `..`.-:. \n");
	printf("      `-:////:::.   \n");
	printf("   `-://////::::   \n");
	printf("  .:///::::::/:`  \n");
	printf(" `:::::://::.  \n");
	printf("  `.....`   \n");
	printf("Input quantity of sugar per serving: "); scanf("%d", &sugar); fflush(stdin);

	printf("	                           `...://- \n");
	printf("                       `.---``-:--/:  \n");
	printf("                     ---..```--..--:/ \n");
	printf("                   `//::::--::-....-:/` \n");
	printf("                   `+++////////-....--/. \n");
	printf("                   :oo//+//////+//::::// \n");
	printf("    ```````.....``  :oo+++//////++///+/` \n");
	printf(".::-........--:://:  .ooo++/++///++++: \n");
	printf("o----.`````.:::/+++// `+oooo//++///-` \n");
	printf("o---..--:-::///////os`  -//:-...``     \n");
	printf("+---....:///////+/+os.    \n");
	printf("/:-.--..-+//////++oos.    \n");
	printf("-/.-..-::o//////++oos- \n");
	printf(".+---////o////+++ooos- \n");
	printf("`++://///o/////::oo/-  \n");
	printf("  `-:/+++o++++/-.`   \n");
	printf("       `...``               \n");
	printf("    ````....````            ``````  \n");

	printf(" \n");
	printf("Input quantity of ice per serving: "); scanf("%d", &ice); fflush(stdin);

	fp = fopen ("recipe.txt", "w");

	fprintf(fp, "%d#%d#%d", lemon, sugar, ice);

	fclose(fp);


	system("pause");
}

void recipe (struct stock *stc, int *pps){
	int l=0, s=0, i=0;
	fp = fopen("recipe.txt","r");
	if(fp==NULL){
		printf("You haven't written any recipe'");
	}
	else{
		fscanf(fp,"%d#%d#%d", &l, &s, &i);
	}
	fclose(fp);

	*pps=l*20+s*10+i*10+15;

	if(stc->lemon<l || stc->glass<1 || stc->ice<i || stc->sugar<s){
		printf("You don't have enough stock. Please buy some first\n");
	}
	else{
		stc->lemon=stc->lemon-l;
		stc->sugar=stc->sugar-s;
		stc->ice=stc->ice-i;
		stc->glass=stc->glass-1;
	}



}

void upgrade(struct stock *stc, struct main *player){
	int upg;
	printf("Current equipment: %s\n", stc->equip);
	printf("Buy:\n");
	printf("1. Medium blender(increase profit by 10%)\t$50000\n");
	printf("2. Gold blender(increase profit by 30%)$500000\n");

	printf("Which one do you want to buy? [press 0 to cancel]\n");
	printf(">>>"); scanf("%d", &upg); fflush(stdin);

	switch(upg){
		case 0: break;
		case 1:
			if(player->money<50000){
				printf("You don't have enough money\n");
			}
			else{
				if(strcmpi(stc->equip, "Medium Blender")==0){
					printf("You've already bought this item\n");
				}
				else{
					printf("Congratulation! Now you have a medium blender!\n");
					player->money=player->money-50000;
					strcpy(stc->equip, "Medium Blender");
				}
			}
			break;
		case 2:
			if(player->money<500000){
				printf("You don't have enough money\n");
			}
			else{
				if(strcmpi(stc->equip, "Gold Blender")==0){
					printf("You've already bought this item\n");
				}
				else{
					printf("Congratulation! Now you have a gold blender! Yay!\n");
					player->money=player->money-500000;
					strcpy(stc->equip, "Gold Blender");
				}
			}
			break;
	}

	system("pause");

}

void rent_place(struct main *player, struct stock *stc){
	int plc=0;
	printf("Current place: %s", stc->place);
	printf("\n\nPlaces available for rent: \n");
	printf("1. Little Town\t\t$0\n");
	printf("2. Big City\t\t$50/day\n");
	printf("3. Cityhall\t\t$100/day\n");
	printf("4. Bazaar\t\t$200/day\n\n");
	printf("Which place do you want to rent? [press 0 to cancel]\n");
	printf(">>>"); scanf("%d", &plc); fflush(stdin);

	switch(plc){
		case 0: break;
		case 1: strcpy(stc->place, "Town Hall");
				break;
		case 2: if (player->money<500){printf("You don't have enough money\n");}
				else{
				if(strcmpi(stc->place, "big city")==0){
					printf("You've already rented this place\n");
				}
				else{
					strcpy(stc->place, "Big City");
					printf("You have successfully rented %s\n", stc->place);
				}
				}
				break;
		case 3: if (player->money<1000){printf("You don't have enough money\n");}
				else{
				if(strcmpi(stc->place, "Cityhall")==0){
					printf("You've already rented this place\n");
				}
				else{
					strcpy(stc->place, "Cityhall");
					printf("You have successfully rented %s\n", stc->place);
				}
				}
				break;
		case 4:	if (player->money<2000){printf("You don't have enough money\n");}
				else{
				if(strcmpi(stc->place, "Bazaar")==0){
					printf("You've already rented this place\n");
				}
				else{
					strcpy(stc->place, "Bazaar");
					printf("You have successfully rented %s\n", stc->place);
				}
				}
				break;
	}
	system("pause");
}

void weather(struct stock *stc){
	int x;

	x=rand()%10+1;
	if (x>1 && x<=7){
		strcpy(stc->weather, "Sunny day");
	}
	else if (x>7){
		strcpy(stc->weather, "Rainy day");
	}
	else if (x==1){
		strcpy(stc->weather, "Storm");
	}
}

void sell(struct main *player, struct stock *stc){
	system("cls");
	int pps=0;
	float b;
	int w, p, e, a;
	int l, s, i, g;
	int profit=0;

	if (stc->glass==0 || stc->ice==0 || stc->lemon==0 || stc->sugar==0){
		printf("\nYou don't have enough stock. Buy some stock first before opening your shop today!\n");
		system("pause");
	}
	else{

	weather(&*stc);

	//weather factor
	if (strcmpi(stc->weather, "Sunny day")==0){
		w=rand()%5+6;
	}
	else if (strcmpi(stc->weather, "Rainy day")==0){
		w=rand()%5+1;
	}
	else if (strcmpi(stc->weather, "Storm")==0){
		w=0;
	}

	//place factor
	if (strcmpi(stc->place, "Little Town")==0){
		p=1;
		player->money=player->money-500;
	}
	else if (strcmpi(stc->place, "Big City")==0){
		p=2;
		player->money=player->money-1000;
	}
	else if (strcmpi(stc->place, "Cityhall")==0){
		p=3;
		player->money=player->money-1500;
	}
	else if (strcmpi(stc->place, "Bazaar")==0){
		p=4;
		player->money=player->money-2000;
	}

	if (strcmpi(stc->booth, "Broken Booth")==0){
		b=1;
	}
	else{
		b=2;
	}

	//equipment factor
	if (strcmpi(stc->equip, "Blender")==0){
		e=1;
	}
	else if (strcmpi(stc->equip, "Medium Blender")==0){
		e=2;
	}
	else if (strcmpi(stc->equip, "Gold Blender")==0){
		e=3;
	}

	//recipe factor
	recipe(&*stc, &pps);


	printf("Price per serving: $%d\n\n", pps);
	printf("Day %d Month %d Year %d \n", player->dd, player->mm, player->yy);
	printf("Weather: %s \n\n\n\n", stc->weather);

gotoxy(20,30);
 printf("         ./osssyyhhyyyyyyss+-");
 Sleep(100);
 gotoxy(20,29);
 printf("       `+yo:.`             `./o+        ");
 Sleep(100);
 gotoxy(20,28);
 printf("       +s    ./+++++oo+++/-   `m`         ");
 Sleep(100);
 gotoxy(20,27);
 printf("       h/  -/-`          `-::` h/      ");
 Sleep(100);
 gotoxy(20,26);
 printf("      `N. .`                 .`os         ");
 Sleep(100);
 gotoxy(20,25);
 printf("      :m `                    `:m    ");
 Sleep(100);
 gotoxy(20,24);
 printf("      os -                    -.N.   ");
 Sleep(100);
 gotoxy(20,23);
 printf("      h/-.                     /h/  ");
 Sleep(100);
 gotoxy(20,22);
 printf("     `N.+                      +oy  ");
 Sleep(100);
 gotoxy(20,21);
 printf("     :d./                      :+m  ");
 Sleep(100);
 gotoxy(20,20);
 printf("     os+.                      `oN.   ");
 Sleep(100);
 gotoxy(20,19);
 printf("     d/s                        sh/  ");
 Sleep(100);
 gotoxy(20,18);
 printf("    `N//                        /sy  ");
 Sleep(100);
 gotoxy(20,17);
 printf("    :do`                        .sm ");
 Sleep(100);
 gotoxy(20,16);
 printf("    oso                          om. ");
 Sleep(100);
 gotoxy(20,15);
 printf("    d+:                          +y+ ");
 Sleep(100);
 gotoxy(20,14);
 printf("   `m+`                          .sy  ");
 Sleep(100);
 gotoxy(20,13);
 printf("   :h/                            om` ");
 Sleep(100);
 gotoxy(20,12);
 printf("   so-                            :d- ");
 Sleep(100);
 gotoxy(20,11);
 printf("   d:                             .s+ ");
 Sleep(100);
 gotoxy(20,10);
 printf("  .d.                              :y  ");
 Sleep(100);
 gotoxy(20,9);
 printf("  :o`                              `d     ");
 Sleep(100);
 gotoxy(20,8);
 printf("  o-                                s.    ");
 Sleep(100);
 gotoxy(20,7);
 printf("  s  `.::::::::::::::::-----------.`-/    ");
 Sleep(100);
 gotoxy(20,6);
 printf("  s:::.`                          `:o/    ");
 Sleep(100);
 gotoxy(20,5);
 printf("  `..------------:---:::---::::::::-`     ");

	profit=(w*p*e*b)*(pps);
	gotoxy(20,32);
	if (strcmpi (stc->weather, "Storm")==0){
		strcpy (stc->booth, "Broken Booth");

		printf("Oh no! Your booth is broken by the storm. You have to buy a new one\n");
	}

	player->money+=profit;
	printf("\nYou got $%d\n", profit);


	system("pause");
	if (player->mm%2==1){
		if (player->dd<31){
			player->dd=player->dd+1;
		}
		else{
			player->dd=01;
			player->mm=player->mm+1;
		}
	}
	else{
		if (player->dd<30){
			player->dd=player->dd+1;
		}
		else{
			player->dd=01;
			if(player->mm<12){
				player->mm=player->mm+1;
			}
			else{
				player->mm=01;
				player->yy=player->yy+1;
			}
		}
	}


	view(*player, *stc);
}
}

void fix(struct main *player, struct stock *stc){
	int fix, f;
	printf("Do you want to fix your booth? (Broken booth will decrease your profit)\n");
	printf("1. Yes\n2.No\n>>>"); scanf ("%d", &fix); fflush(stdin);
	if (fix==1){
		printf("Booth repair costs $10000\nProceed?\n\n1.Yes, proceed\n2.No, I've changed my mind\n>>>"); scanf ("%d", &f); fflush(stdin);
		if (f==1){
			if (player->money>10000){
				player->money=player->money-10000;
				strcpy (stc->booth, "Booth");
				printf("\nRepair successful!\n");
			}
			else{
				printf("\nYou don't have enough money\n");
			}
		}
		else{
		}
	}
	else{
	}
	system("pause");
}

void menus(struct main player, struct stock stc, int pps){
int z;

do{
system("cls");
printf("Lemonade Tycoon\n\n");
printf("1. view info \n");
printf("2. buy stock \n");
printf("3. change recipe \n");
printf("4. upgrade equipment \n");
printf("5. rent place \n");
printf("6. sell lemonade \n");
printf("7. save and exit \n");
if (strcmpi(stc.booth, "Broken Booth")==0){
	printf("8. Fix booth \n");
}


printf("What do you want to do? \n");
printf(">>>"); scanf("%d", &z);

switch(z){
	case 1: view(player, stc); break;
	case 2: buy(&stc,&player); break;
	case 3: change_recipe();
			break;
	case 4: upgrade(&stc, &player); break;
	case 5: rent_place(&player, &stc); break;
	case 6: sell(&player, &stc); break;
	case 7: save(player, stc); break;
	case 8:
			if (strcmpi(stc.booth, "Broken Booth")==0){ fix(&player, &stc);	}
			else { printf("\n\nMenu unavailable\n");}
			break;
}
}while(z!=7);

}

int main(){
	srand(time(NULL));
	int choose=0;
	int pps;
	struct main player;
	struct stock stc;

	choose=menu();

	switch(choose){
		case 1: new_(player, stc);
				load (&player, &stc);
				menus(player, stc, pps);
				break;
		case 2: load (&player, &stc);
				menus(player, stc, pps);
				break;
	}

	return 0;
}
