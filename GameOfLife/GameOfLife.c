/*We will implement Conway's game of life in C
The rules of the game are as follows

1)Any live cell with two or three live neighbours survives.
2)Any dead cell with three live neighbours becomes a live cell.
3)All other live cells die in the next generation. Similarly, all other dead cells stay dead.


The game is played on a grid of cells where each cell can be either alive or dead.
We will assume that the grid wraps around all edges
In particular the rightmost-leftmost edges and top-bottom edges are assumed to be adjacent
The grid is finite but very large
The grid is represented as a 2D array of cell structs with fields
	int position[2] //position of the cell in the grid
	int alive
	int liveNeighbors


The grid is initialized with a random configuration of live and dead cells
or with a configuration specified by the user
The user can also specify the size of the grid upto a given maximum size
The user can also specify the number of generations to simulate
The program will clear the screen and print the grid after each generation
The program will also print the number of live cells in the grid after each generation

We will use data structures that minimize  the number of operations performed
We will use a 2D array of struct cells to represent the grid
We will use a 2D array of integers to store the live cells in the grid

*/
//###################INCLUDES#####################
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#define MAX 20
#define LIVEMAX 100
#pragma warning(disable : 4996) //Use this only in Visual Studio

//###################DATA STRUCTURES#####################

typedef struct cellType {
	int position[2];
	int alive;
	int liveNeighbors;
	int listIndex;
} cell;

//###################FUNCTION DECLARATIONS#####################

void initializeGrid();

int countNeighbors(cell center);

void printGrid( );

void printStatus();

int mod(int, int);

void setCell( int i, int j);

void getNeighbors( int i, int j, int  neighbours[8][2]);

void delCell( int i);

void swapCell(int i, int j);
//###################GLOBAL VARIABLES#####################

cell grid[MAX][MAX];

int numLiveCells = 0, numOfAdjDeadCells = 0, numOfMarkedCells = 0;

int rows = MAX, cols = MAX, generations=0;
int liveCells[LIVEMAX][2];
int markedCells[LIVEMAX][2];


int main() {

	
	initializeGrid();
	generations = 1;
	
	while (numLiveCells > 0) {
		
		//mark the cells that will change state in the next generation
		for (int i = 0; i < numLiveCells; i++) {
			int xI = liveCells[i][0];
			int xJ = liveCells[i][1];
			
			if (grid[xI][xJ].liveNeighbors > 3 || grid[xI][xJ].liveNeighbors < 2) {
				
				grid[xI][xJ].alive = -1;
				
				
				markedCells[numOfMarkedCells][0] = xI;
				
				markedCells[numOfMarkedCells][1] = xJ;
				numOfMarkedCells++;
		//		printf("The cell at position %d,%d will die in the next generation\n", xI, xJ);
			}

		}

	//	printf("numofAdjDead:%d\n", numOfAdjDeadCells);
		for (int i = 0; i < numOfAdjDeadCells; i++) {

			int xI = liveCells[LIVEMAX - i-1][0];
			int xJ = liveCells[LIVEMAX - i-1][1];
			
			if (grid[xI][xJ].liveNeighbors == 3) {
				grid[xI][xJ].alive = 2;
				markedCells[numOfMarkedCells][0] = xI; 
				markedCells[numOfMarkedCells][1] = xJ;
				numOfMarkedCells++;
	//			printf("The cell at position %d,%d will be revived in the next generation\n", xI, xJ);
			}
		}
	//	printf("Status before set marked\n");
	//	printStatus();
		for (int i = 0; i < numOfMarkedCells; i++) {
			
			setCell(markedCells[i][0], markedCells[i][1]);

		}
		numOfMarkedCells = 0;
	//	printf("Status after set marked\n#####################################\n");
		//printStatus();
		printGrid();
		printf("generation:%d\n", generations);
		Sleep(40);
		generations++;
		
		
	}
}

int countNeighbors( cell center) {

	//This function counts the number of live neighbors of a cell considering that the edges wrap around

int count = 0;
int i = center.position[0];
int j = center.position[1];

//We will count the number of live neighbors of cell i,j
//We will assume that the grid wraps around all edges
//In particular the rightmost-leftmost edges and top-bottom edges are assumed to be adjacent
//We will use the following convention for the neighbors of a cell
//The neighbors of cell i,j are cells i-1,j-1, i-1,j, i-1,j+1, i,j-1, i,j+1, i+1,j-1, i+1,j, i+1,j+1
//We will use the % operator to implement the wrap around
//For example if i=0 then i-1=-1 but i-1%MAX=99
//Similarly if j=MAX-1 then j+1=MAX but j+1%MAX=0

int res= grid[mod((i + 1), rows)][j].alive + grid[mod((i - 1), rows)][j].alive + grid[i][mod((j + 1), cols)].alive + grid[i][mod((j - 1), cols)].alive + grid[mod((i + 1), rows)][mod((j + 1), cols)].alive + grid[mod((i + 1), rows)][mod((j - 1), cols)].alive + grid[mod((i - 1), rows)][mod((j + 1), cols)].alive + grid[mod((i - 1), rows)][mod((j - 1), cols)].alive;
//(grid + mod((i + 1) , rows) * cols + j )->alive + (grid + mod((i - 1) , rows) * cols + j )->alive + (grid + i * MAX + mod((j + 1) , cols))->alive + (grid + i * cols + mod((j - 1) , cols))->alive + (grid + mod((i + 1) , rows) * cols + mod((j + 1) , cols))->alive + (grid + mod((i + 1) , rows) * cols + mod((j - 1) , cols))->alive + (grid + mod((i - 1) , rows) * cols + mod((j + 1) , cols))->alive + (grid + mod((i - 1) , rows) * cols + mod((j - 1) , cols))->alive;
return res;







}
int mod(int a, int b) {

	return (a % b + b) % b;

}
void printStatus() {

	for (int i = 0; i < numLiveCells; i++) {

		printf("live i: %d j:%d neigh:%d alive:%d\n", liveCells[i][0], liveCells[i][1], grid[liveCells[i][0]][liveCells[i][1]].liveNeighbors, grid[liveCells[i][0]][liveCells[i][1]].alive);
	}
	for (int i = 0; i < numOfAdjDeadCells; i++) {
		int xI = LIVEMAX - i - 1;
		printf("adj i: %d j:%d neigh:%d alive:%d\n", liveCells[xI][0], liveCells[xI][1], grid[liveCells[xI][0]][liveCells[xI][1]].liveNeighbors, grid[liveCells[xI][0]][liveCells[xI][1]].alive);
	}
	for (int i = 0; i < numOfMarkedCells; i++) {

		printf("marked i: %d j:%d status:%d neigh:%d\n", markedCells[i][0], markedCells[i][1],grid[markedCells[i][0]][ markedCells[i][1]].alive, grid[markedCells[i][0]][markedCells[i][1]].liveNeighbors);
	}
}
void printGrid() {

	system("cls");
	for (int i = 0; i < rows; i++) {
		printf("|");
		for (int j = 0; j < cols; j++) {

			if (grid[i][j].alive==1) {
				printf("X|");
			}
			else{
				printf(" |");
			}
			
		}

		printf("\n");

	}


}
void initializeGrid() {

	printf("Initializing grid\n");
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++) {
			
			grid[i][j].position[0] = i;
			grid[i][j].position[1] = j;
			grid[i][j].alive = 0;
			grid[i][j].liveNeighbors = 0;
			
		}

	addGlider(0, 0);
	addGlider(6, 16);

	/*
	for (int i = 0 ; i<3; i++)
		for (int j = 0; j < 3; j++) {
			if (i + j){
				grid[i][j].alive = 2;
		

				}
			

		}
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++) {
			if (i + j) {
		
				setCell(i, j);

			}


		}
		*/
/*
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++) {
			grid[i][j].liveNeighbors = countNeighbors(grid[i][ j]);
		}
		*/
	printGrid(grid, rows, cols);
	//printStatus();




}

void setCell( int i, int j) {
	
	int  neighbours[8][2];
	
	getNeighbors( i, j, neighbours);

	if (grid[i][j].alive == -1) {
		delCell(grid[i][j].listIndex);
		if (grid[i][j].liveNeighbors > 0) {
			++numOfAdjDeadCells;
			
			liveCells[LIVEMAX - numOfAdjDeadCells][0] = i;

			liveCells[LIVEMAX - numOfAdjDeadCells][1] = j;

			grid[i][j].alive = 9;
			
			grid[i][j].listIndex = LIVEMAX - numOfAdjDeadCells;

		}
		else {
			grid[i][j].alive = 0;
			
		}
		

		

		for (int  k = 0; k<8; k++) {
			
			int nI = neighbours[k][0];
		
			int nJ = neighbours[k][1];
			
			grid[nI][nJ].liveNeighbors--;
			
			if (grid[nI][nJ].liveNeighbors == 0){
			
				if (grid[nI][nJ].alive != 2 && grid[nI][nJ].alive != 1) {
					if (grid[nI][nJ].alive == 9) {
						delCell(grid[nI][nJ].listIndex);
						grid[nI][nJ].alive = 8;

					}
						
			//		printf("marked to remove from adj nI: %d nJ: %d\n", nI, nJ);
					
					markedCells[numOfMarkedCells][0] = nI;
					
					markedCells[numOfMarkedCells][1] = nJ;
					
					numOfMarkedCells++;
				}
			}
		}

		//top left
		

	}
	else if(grid[i][j].alive==2) {
		
		grid[i][j].alive = 1;
		
		if (generations > 0) {
		
			//printf("Adding live i:%d j:%d\n", i, j);
			
			delCell(grid[i][j].listIndex);
		
		}
		
		liveCells[numLiveCells][0] = i;
		
		liveCells[numLiveCells][1] = j;
		
		grid[i][j].listIndex = numLiveCells;
		
		numLiveCells++;
		
		for (int k = 0; k < 8; k++) {
		
			int nI = neighbours[k][0];
			
			int nJ = neighbours[k][1];
			
			grid[nI][nJ].liveNeighbors++;
			
			if (grid[nI][nJ].liveNeighbors == 1) {
			
				if (grid[nI][nJ].alive == 0 || grid[nI][nJ].alive == 8) {
			
				//	printf("Adding adj nI: %d nJ: %d alive:%d\n", nI, nJ, grid[nI][nJ].alive);
					
					++numOfAdjDeadCells;
					
					liveCells[LIVEMAX - numOfAdjDeadCells][0] = nI;
					
					liveCells[LIVEMAX - numOfAdjDeadCells][1] = nJ;
					
					grid[nI][nJ].alive = 9;

					grid[nI][nJ].listIndex = LIVEMAX - numOfAdjDeadCells;
				}
				if (grid[nI][nJ].alive == 8) {

					grid[nI][nJ].alive = 9;

				}
				
				
			}
		}
		//top left
		
	}
	else if(grid[i][j].alive == 8) {

		//delCell(grid[i][j].listIndex);
		
		grid[i][j].alive = 0;
	}
	//else if (grid[i][j].alive==9){

		//printf("i:%d j:%d dondu\n",i,j);
		
	//}
}

void getNeighbors(int i, int j, int neighbours[8][2]) {

	neighbours[0][0] =  mod(i - 1, rows) ;
	neighbours[1][0] =  mod(i - 1, rows) ;
	neighbours[2][0] =  mod(i - 1, rows) ;
	neighbours[3][0] = i;
	neighbours[4][0] = i ;
	neighbours[5][0] = mod(i + 1, rows) ;
	neighbours[6][0] = mod(i + 1, rows) ;
	neighbours[7][0] = mod(i + 1, rows);

	neighbours[0][1] = mod(j - 1, cols);
	neighbours[1][1] = j;
	neighbours[2][1] = mod(j + 1, cols);
	neighbours[3][1] = mod(j - 1, cols);
	neighbours[4][1] =  mod(j + 1, cols);
	neighbours[5][1] = mod(j - 1, cols);
	neighbours[6][1] = j;
	neighbours[7][1] =  mod(j + 1, cols);


}

void delCell(int i) {
	cell* copiedCell;
	if (i < numLiveCells) {

		copiedCell = &grid[liveCells[numLiveCells - 1][0]][liveCells[numLiveCells-1][1]];
		numLiveCells--;

	}
		
	else { 
		 copiedCell = &grid[liveCells[LIVEMAX - numOfAdjDeadCells][0]][liveCells[LIVEMAX - numOfAdjDeadCells][1]]; 
		 numOfAdjDeadCells--;
	}
	liveCells[i][0] = copiedCell->position[0];
	liveCells[i][1] = copiedCell->position[1];
	copiedCell->listIndex = i;
	
	
		



}

void addGlider(int i, int j) {

	grid[i+1][j+0].alive = 2;
	grid[i + 2][j + 1].alive = 2;
	grid[i + 0][j + 2].alive = 2;
	grid[i + 1][j + 2].alive = 2;
	grid[i + 2][j + 2].alive = 2;

	setCell(i + 1, j + 0);
	setCell(i + 2, j + 1);
	setCell(i + 0, j + 2);
	setCell(i + 1, j + 2);
	setCell(i + 2, j + 2);


}

void cpyCell(int i, int j) {
	//This function will be used to swap cells in the living cells list
	//The possible reasons for such a swap are tied to the setCell functions configuration

	
	int destRow = liveCells[i][0];
	int destCol = liveCells[i][1];
	int srcRow = liveCells[j][0];
	int srcCol = liveCells[j][1];

	



	cell *destCell = &grid[destRow][destCol];
    cell *srcCell = &grid[srcRow][srcCol];

	srcCell->listIndex = destCell->listIndex;


}

/*
void getNeighbors(int i, int j, cell* neighbours[8]) {

	neighbours[0] = (grid + mod(i - 1, rows) * MAX + mod(j - 1, cols));
	neighbours[1] = (grid + mod(i - 1, rows) * MAX + j);
	neighbours[2] = (grid + mod(i - 1, rows) * MAX + mod(j + 1, cols));
	neighbours[3] = (grid + i * MAX + mod(j - 1, cols));
	neighbours[4] = (grid + i * MAX + mod(j + 1, cols));
	neighbours[5] = (grid + mod(i + 1, rows) * MAX + mod(j - 1, cols));
	neighbours[6] = (grid + mod(i + 1, rows) * MAX + j);
	neighbours[7] = (grid + mod(i + 1, rows) * MAX + mod(j + 1, cols));



}*/