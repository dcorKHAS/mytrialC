
#include <stdio.h>
#include <conio.h>

#define H 3
#define W 3
//A two dimensional board where the user can press {W,A,S,D} to move a symbol in the board

//Take input

//Keep track of the symbols location

//We should draw the board with the symbol in correct position

//Use _getch() from conio.h instead of scanf() for input

void printBoard(char board[H][W]); //function declaration

int main() {


	//The game board is actually a matrix;

	char board[H][W] = { {'$',' ',' '},{' ',' ',' '},{' ',' ',' '} };
	int position[2] = {0,0}; // row and column of the symbol 
	printBoard(board);
	int pressedButton;
	
	while (pressedButton = _getch()) {
		
		board[position[0]][position[1]] = ' ';

		switch (pressedButton) {

		case 'w':
							
			position[0]--;
			break;
		
		case 's':

			position[0]++;
			break;

		case 'a':

			position[1]--;
			break;

		case 'd':
						
			position[1]++;
			break;

		}
		board[position[0]][position[1]] = '$';
		printBoard(board);
	}
}

void printBoard(char board[H][W]) {

	//printf("printBoard function is called.\n");
	system("cls");
	for (int i = 0; i < H; i++) {
		printf("|");
		for (int j = 0; j < W; j++) {

			printf("%c|", board[i][j]);

		}

		printf("\n");

	}
}
//Please implement the following modifications:

//1) Do not allow the symbol to go outside the board
//2)Initialize the board with nested loops instead of a fixed initializer
//3) Assign "q" as the key to end the game

