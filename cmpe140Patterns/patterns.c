#include <stdio.h>
void lowerLeftTriangle(int n);
void squarePattern(int n);
void rectanglePattern(int n, int m);
void lowerRightTriangle(int n);
void pyramidPattern(int n);

void pascalsTriangle(int n);
int main() {


	//squarePattern(6);
	//rectanglePattern(3, 10);
	//lowerLeftTriangle(6);
	//lowerRightTriangle(10);
	//pyramidPattern(10);
	pascalsTriangle(10);
	return 0;

}

void squarePattern(int n) {



	for (int i = 0; i < n; i++) {

		for (int j = 0; j < n; j++) {

			printf("* ");

		}
		printf("\n");
	}
}

void rectanglePattern(int n, int m) {
	
	//n rows m columns

	for (int i = 0; i < n; i++) {

		for (int j = 0; j < m; j++) {

			printf("* ");

		}
		printf("\n");
	}


}

void lowerLeftTriangle(int n) {

	

	for (int i = 0; i < n; i++) {

		for (int j = 0; j < i+1; j++) {

			printf("*");

		}
		printf("\n");
		
	}


	/*
	
	*
	**
	***
	****
	*****
	******

		*/


}


void lowerRightTriangle(int n) {



	for (int i = 0; i < n; i++) {

		for (int j = 0; j < n; j++) {

			if (j < n - (i+1)) {

				printf(" ");
			}
			else {
				printf("*");
			}

		}
		printf("\n");

	}


	/*

		*
	   **
	  ***
	 ****
	*****
   ******

		*/


}


void pyramidPattern(int n) {

	for (int i = 1; i < n+1; i++) {

		for (int j = 1; j < 2*n; j++) {

			// 2i-1 is the number of stars on line i
			//2n-1 is the width
			// 2n-1 - (2i-1) is the number spaces 2(n-i)
			// spaces on the right side n-i

			if (j > n-i && j < 2*n-(n-i) ) {

				printf("*");

			}
			else {

				printf(" ");
			}

		}
		printf("\n");
	}


}

/*
		   *
		  ***
		 *****
		*******
		  ...
	 *****...****  2n-1 stars on the last line

	n lines with 2i-1 stars on line i

	*/
void pascalsTriangle(int n) {

	int prevLine[3000];
	int line[3000];
	line[0] = 1;
	line[1] = -1;
	
		for (int h = 0; h < n +2; h++) {
			printf("  ");
	}
	
		
		
		for (int j = 0; line[j] != -1; j++) {
			
			printf("%-4d", line[j]);
		}
		printf("\n");
		
	





	line[0] = 1;
	line[1] = 1;
	line[2] = -1;
	
	
		for (int h = 0; h < n +1; h++) {
			printf("  ");
		}
		


		for (int j = 0; line[j] != -1; j++) {

			printf("%-4d", line[j]);
		}
		printf("\n");

	
	prevLine[0] = 1;
	prevLine[1] = 1;
	prevLine[2] = -1;

	//prevLine[3] = -1;

	for (int k = 0; k < n; k++) {
		for (int h = 0; h < n - k; h++) {
			printf("  ");
	}
			line[0] = 1;
		int i = 1;
		for (; prevLine[i] != -1; i++) {

			line[i] = prevLine[i] + prevLine[i - 1];
		}
		line[i] = 1;
		line[i + 1] = -1;
		
		int j = 0;
		for (; line[j] != -1; j++) {
			
			printf("%-4d", prevLine[j]);
			prevLine[j] = line[j];
		}
		prevLine[j] = -1;
		printf("\n");
		
	}
}

     /*
	 
				 1
			   1   1
			1    2   1
		  1   3    3   1 
	    1   4    6   4   1
	           ...
	 
	 
	 
	 
	 */




