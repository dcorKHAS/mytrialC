#include <stdio.h>
/*
P//lease write a c function that accepts an integer argument n and prints the following pattern

***...***
***...***
***...***
***...***
...
***...***
n stars for n lines
*/
int rectanglePattern(int n, int m);
int squarePattern(int n);
int main() {

	//You can take input here

	squarePattern(6);
	rectanglePattern(3, 5);

}

int squarePattern(int n) {


	for (int i = 0; i < n; i++) {

		for (int j = 0; j < n; j++) {

			//here will be repeated n*n times
			printf("*");

		}
		printf("\n");
	}
}
int rectanglePattern(int n, int m) {


	for (int i = 0; i < n; i++) {

		for (int j = 0; j < m; j++) {

			//here will be repeated n*n times
			printf("*");

		}
		printf("\n");
	}


}
int lowerLeftTrianglePattern(int n) {
	/*
	//
	*
	**
	***
	****
	...
	*****...**
	increasing number of stars at every line for n lines
	e.g.
	n=5
	*
	**
	***
	****
	*****


	*/

}
int lowerRightTrianglePattern(int n) {
	
	for () {

		for () {

			if ()
				print("*")
			else
				print(" ")

		}
	}
	/*
	//
			*
		   **
		  ***
		 ****
		  ...
	*****...*
	increasing number of stars aligned to right at every line for n lines
	e.g.
	n=5
		*
	   **
      ***
	 ****
	*****


	*/
	//printf(" ");
}


int pyramidPattern(int n) {


	/*
		   *
		  ***
		 *****
		******* 
		  ...
	 *****...****
			  
	n lines with 2i-1 stars on line i   

	*/
}










}












