//A 2d Board where the user can move a symbol with {W,A,S,D}
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define ROWS 8
#define COLS 8



int board[ROWS][COLS];
//0 for empty 1 for full
int position[2] = { 0,0 };
void moveObject(char movement);

void printBoard();

int main() {


	char pressedButton;

	while (1) {

		//infinite loop

		//take input
		pressedButton = _getch();
		//scanf("%c", &pressedButton);
		//getchar();


		moveObject(pressedButton);
		printBoard();
		
		//Later: Clear screen

	}
	return 0;
}



void moveObject(char movement) {

	//Write 0 to old position

	board[position[0]][position[1]] = 0;

	switch (movement) {

		case 'w':
			if(position[0]>0)
				position[0]--;
			

			break;
		
		case 'a':
			if (position[1] >0 )
			position[1]--;
			
			break;
		case 's':
			if (position[0] < ROWS-1)
			position[0]++;
			
			break;


		case 'd':
			if (position[1] < COLS-1) {
				position[1]++;
			}
			
			
			break;

	}
	//Write 1 to new position
	board[position[0]][position[1]] = 1;
	

	

}

void printBoard() {
	system("cls");

	for (int i = 0; i < ROWS; i++) {
		printf("|");
		for (int j = 0; j < COLS; j++) {

			if (board[i][j]) {

				printf("#|");
			}
			else {
				printf(" |");
			}

			//printf("%d",board[i][j]);

		}
		printf("\n");

	}




 }
