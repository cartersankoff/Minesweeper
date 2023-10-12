#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10
#define BOMBS 15


int countAdjacentBombs(char board[SIZE][SIZE], int x, int y){
    int n=0;
        for (int checkRow = x-1; checkRow <= x+1; checkRow++){
            for (int checkCol = y-1; checkCol<=y+1; checkCol++){
                if (checkRow>=0 && checkRow<SIZE && checkCol>=0 && checkCol<SIZE) {
                    if (board[checkCol][checkRow] == 'X') {
                        n++;
                    }
                }
            }
        }
         return n + '0';
    }


void printBoard(char displayBoard[SIZE][SIZE]){
    for (int i=0; i < SIZE; i++){
        for (int j=0; j < SIZE; j++){
            printf("%c ", displayBoard[i][j]);
        }
        printf("\n");
    }
}

void placeBombs(char board[SIZE][SIZE]){

    srand(time(NULL));
    int i = 0;

    while (i<BOMBS){
        int bombX = rand() % 10;
        int bombY = rand() % 10;

        if (board[bombX][bombY] == '-'){
            board[bombX][bombY] = 'X';
            i++;

        }

        else{
            continue;
        }
    }
}


int main(void) {

    char board[SIZE][SIZE];
    char displayBoard[SIZE][SIZE];
    int gameOver = 0;
    int remainingCells = SIZE * SIZE - BOMBS;

    for (int i=0; i<SIZE; i++){
        for (int j=0; j<SIZE; j++){
            board[i][j] = '-';
            displayBoard[i][j] = '-';
        }
    }

    printf("Welcome to Minesweeper!\nEnter the coordinates (x y) to reveal a cell.\n");
    placeBombs(board);
    printBoard(displayBoard);

    while (remainingCells > 0 && !gameOver){
        int x, y;
        printf("Enter coordinates (x y): ");
        scanf("%d %d", &x, &y);

            if (x>=SIZE || x<0 || y>=SIZE || y<0){
                printf("Invalid Input. Try again\n");
                continue;
            }

            else if (board[y][x]=='X'){
                printf("Game Over! You hit a bomb.\n");
                printBoard(board);
                gameOver = 1;
            }

            else if (board[y][x]!='-'){
                printf("Already guessed :( try again\n");
                continue;
            }

            else {
                int bombCount=countAdjacentBombs(board, x, y);
                board[y][x]=bombCount;
                displayBoard[y][x]= bombCount;
                printBoard(displayBoard);
                remainingCells--;
                printf("Remaining cells: %d", remainingCells);
            }
        }
    }

