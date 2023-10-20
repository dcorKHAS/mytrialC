#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <conio.h>
#include <stdlib.h> //system function is also defined in this library

#define H 5
#define W 5

// two dimensional board where the user can press {W,A,S,D} to move a symbol in the board

//Take input

//Keep track of the symbol's location

//We should draw the board with the symbol in correct position

//Use _getch() from conio.h instead of scanf() for input

void printBoard(char board[H][W]); //function declaration

int main() {


	//The game board is actually a matrix;

	char board[H][W];
	
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			//matrix traversal
			board[i][j] = ' ';

		}
	}

	//{ {'$',' ',' '},{' ',' ',' '},{' ',' ',' '} };
	int position[2] = { H/2, W/2 }; // row and column of the symbol 
	board[position[0]][position[1]]= '$';
	printBoard(board);
	char pressedButton;
	
	while (scanf("%c[^\n]", &pressedButton)  ){
		//scanf("%c[^ \n]", &pressedButton); //as an alternative to the additional getchar() function, we can use scanf("%c[^ \n]", &pressedButton);
		//to avoid the newline character in scanf, we can use getchar() after scanf
		board[position[0]][position[1]] = ' ';
		
		switch (pressedButton) {

		case 'w':
			if(position[0]>0)
			position[0]--;
			break;

		case 's':
			if(position[0]<H-1)
			position[0]++;
			break;

		case 'a':
			if(position[1]>0)
			position[1]--;
			break;

		case 'd':
			if (position[1] < W - 1)
				position[1]++;
			break;
		case 'q':
			printf("GAME OVER");
			return 0;

			
		}
		board[position[0]][position[1]] = '$';
		printBoard(board);
	}
}

void printBoard(char board[H][W]) {

	//printf("printBoard function is called.\n");
	system("cls");//corresponding command for linux is "clear",  system("clear");
	for (int i = 0; i < H; i++) {
		printf("|");
		for (int j = 0; j < W; j++) {

			printf("%c|", board[i][j]);

		}

		printf("\n");

	}
}
//Please implement the following modifications:

//
//  -1 % 8 = -1 //C's modulo operator is not mathematically correct
//  
// 
// 
//a function that always return the positive modulo

int mod(int a, int b) {
	
	return (a % b + b) % b;
	
}


//1)Do not allow the symbol to go outside the board (wrap around or hard wall)
//2)Initialize the board with nested loops instead of a fixed initializer
//3)Assign "q" as the key to end the game //Hint: Use a break statement or modify while condition
// 
//4)Add a second symbol to the board and allow the user to move it with {I,J,K,L}
