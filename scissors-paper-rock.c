#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <string.h>


#define RED "\x1b[91m"
#define GREEN "\x1b[92m"
#define YELLOW "\x1b[93m"
#define RESET "\x1b[0m"


char choices[3][8] = {"rock", "paper", "scissors"};

char* computer_choice(void) {
	int i;
	char* choice;
	srand(time(NULL));
	i = rand() % 3;
	choice = choices[i];
	return choice;
}


int check_input(char *choice) {
	for (int i = 0; choice[i]!='\0'; i++) {
		choice[i] = tolower(choice[i]);
	}
	
	for (int i = 0; i<3; i++) {
		int result = strcmp(choices[i], choice);	
		if (result == 0) {
			return 0; 
		} 
	}
	
	return 1;
}


int determine_winner(char *p_choice, char *c_choice) {
    char player = p_choice[0];
	char computer = c_choice[0];

	if (player == computer) {
		printf(YELLOW "You both picked %s, it's a tie!\n", p_choice);
		return 0;
	}
	
	switch (player) {
		case 'r':
			if (computer == 's') {	
				printf(GREEN "You won! Rock smashes scissors!\n");
				return 1;
			} else {
				printf(RED "You lost! Paper covers rock!\n");
				return -1;
			}
	
		case 's':
			if (computer == 'p') {	
				printf(GREEN "You won! Scissors cuts paper!\n");
				return 1;
			} else {
				printf(RED "You lost! Rock smashes scissors!\n");
				return -1;
			}
		
		case 'p':
				if (computer == 'r') {	
					printf(GREEN "You won! Paper covers rock!\n");
					return 1;
				} else {
					printf(RED "You lost! Scissors cuts paper!\n");
					return -1;	
				}
	}
}

void main(void) {
	char p_choice[8], *c_choice;
	int allowed, win;
	char play_again;
	printf("This is a simple Scissors Paper Rock game, made in C!\n");
	do {
			allowed = 1;
			win = 0;
			p_choice[0] = 0;
			fflush(stdin);
			printf("Enter your selection\n");

			while (allowed == 1) {
				printf("[Scissors, Paper, Rock]\n > ");
				scanf(" %s", &p_choice);
				allowed = check_input(p_choice);	
				if (allowed == 1) {
					printf("\nNot a valid choice, make another selection\n");
				}
			}
			
			c_choice = computer_choice();				
				
			printf("\nYou chose %s, the computer chose %s\n", p_choice, c_choice);
			win = determine_winner(p_choice, c_choice);

			printf(RESET "\nWould you like to play again? [Y/n]\n > ");
			getchar();
			play_again = getchar();
			printf("\n");					
	} while (tolower(play_again) != 'n');
}
