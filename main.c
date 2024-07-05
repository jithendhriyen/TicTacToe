#include <stdio.h>

#include <stdlib.h>

#include <time.h>

#define ARRAY_SIZE(arr)(sizeof(arr) / sizeof(arr[0]))

char board[3][3];
char PLAYER, COMPUTER;

struct coord {
  int row;
  int col;
}
coord;

void charSelect();
void resetBoard();
void printBoard();
void playerInput();
void computerInput();
void checkWinner();

int main() {
  char choice;
  do {
    printf("\nWelcome to TicTacToe in pure C\n\n");
    resetBoard();
    charSelect();

    for (int i = 1; i < 10; i++) {
      if ((i % 2 != 0) && (PLAYER == 'X')) {
        playerInput();
        printBoard();
        checkWinner();
      } else if ((i % 2 != 0) && (COMPUTER == 'X')) {
        printf("Computer's Turn:\n");
        computerInput();
        printBoard();
        checkWinner();
      } else if ((i % 2 == 0) && (PLAYER == 'O')) {
        playerInput();
        printBoard();
        checkWinner();
      } else if ((i % 2 == 0) && (COMPUTER == 'O')) {
        printf("Computer's Turn:\n");
        computerInput();
        printBoard();
        checkWinner();
      }
    }

    printf("Do you want to play again (y/n): ");
    scanf(" %c", & choice);

  } while (choice == 'y');

  return 0;
}

void charSelect() {
  printf("Do you want to play as \"X\" or \"O\": ");
  scanf(" %c", & PLAYER);
  printf("\n");
  if (PLAYER == 'X')
    COMPUTER = 'O';
  else
    COMPUTER = 'X';
}

void resetBoard() {
  for (int i = 0; i < ARRAY_SIZE(board); i++) {
    for (int j = 0; j < ARRAY_SIZE(board[0]); j++) {
      board[i][j] = ' ';
    }
  }
}

void printBoard() {
  printf("\n");
  for (int i = 0; i < ARRAY_SIZE(board); i++) {
    for (int j = 0; j < ARRAY_SIZE(board[0]); j++) {
      printf(" %c", board[i][j]);
      if (j < 2) {
        printf(" |");
      }
    }
    if (i < 2) {
      printf("\n-----------\n");
    } else {
      printf("\n\n");
    }
  }
}

void playerInput() {
  do {
    printf("Enter row number (1-3): ");
    scanf("%d", & coord.row);
    printf("Enter column number (1-3): ");
    scanf("%d", & coord.col);

    if (board[coord.row - 1][coord.col - 1] == ' ') {
      board[coord.row - 1][coord.col - 1] = PLAYER;
      break;
    } else {
      printf("\nThat space is not free. Enter again.\n");
    }
  } while (1);
}

void computerInput() {
  do {
    srand(time(NULL));
    coord.row = (rand() % 3) + 1;
    coord.col = (rand() % 3) + 1;

    if (board[coord.row][coord.col] == ' ') {
      board[coord.row][coord.col] = COMPUTER;
      break;
    }
  } while (1);
}

void checkWinner() {
  for (int i = 0; i < ARRAY_SIZE(board); i++) {
    if (board[i][0] != ' ' && ((board[i][0] == board[i][1])) && (board[i][0] == board[i][2])) {
      if (board[i][0] == PLAYER) {
        printf("You won\n");
        exit(0);
      } else {
        printf("Computer won\n");
        exit(0);
      }
    }
  }

  for (int i = 0; i < ARRAY_SIZE(board); i++) {
    if (board[0][i] != ' ' && ((board[0][i] == board[1][i])) && (board[0][i] == board[2][i])) {
      if (board[0][i] == PLAYER) {
        printf("You won\n");
        exit(0);
      } else {
        printf("Computer won\n");
        exit(0);
      }
    }

    if (board[0][0] != ' ' && (board[0][0] == board[1][1]) && (board[0][0] == board[2][2])) {
      if (board[0][0] == PLAYER) {
        printf("You won\n");
        exit(0);
      } else {
        printf("Computer won\n");
        exit(0);
      }
    } else if (board[2][2] != ' ' && (board[2][2] == board[1][1]) && (board[2][2] == board[0][0])) {
      if (board[2][2] == PLAYER) {
        printf("You won\n");
        exit(0);
      } else {
        printf("Computer won\n");
        exit(0);
      }
    }
  }
}
