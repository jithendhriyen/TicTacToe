#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof(arr[0]))

char board[3][3];
char PLAYER,COMPUTER;

void charSelect();
void resetBoard();
void printBoard();

int main(){
	printf("Welcome TicTacToe in pure C\n\n");
	charSelect();
	resetBoard();
	printBoard();
	return 0;
}

void charSelect(){
	printf("Do you want to play as \"X\" or \"O\": ");
       	scanf("%c",&PLAYER);
	printf("\n");
	if (PLAYER == 'X')
		COMPUTER = 'O';
	else
		COMPUTER = 'X';
}

void resetBoard(){
	for (int i = 0;i < ARRAY_SIZE(board);i++){
		for (int j = 0;j < ARRAY_SIZE(board[0]);j++){
				board[i][j] = ' ';
		}
	}
}

void printBoard(){
	for (int i = 0;i < ARRAY_SIZE(board);i++){
		for (int j = 0;j < ARRAY_SIZE(board[0]);j++){
				printf(" %c",board[i][j]);
				if (j < 2)
					printf(" |");
		}
		if (i < 2)
			printf("\n-----------\n");
		else
			printf("\n");
	}
}
