#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char board[3][3];
char PLAYER,COMPUTER;

void charSelect();

int main(){
	printf("Welcome TicTacToe in pure C\n\n");
	charSelect();
	printf("%c\n%c\n",PLAYER,COMPUTER);
	return 0;
}

void charSelect(){
	printf("Do you want to play as \"X\" or \"O\": ");
       	scanf("%c",&PLAYER);
	if (PLAYER == 'X')
		COMPUTER = 'O';
	else
		COMPUTER = 'X';
}
