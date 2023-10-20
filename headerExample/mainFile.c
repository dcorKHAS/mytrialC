#include <stdio.h>
#include "functionImplementation.h"
#include <time.h>
//#include <stdlib.h>




long long int j = 300; //global variable
void printGlob();
int main(){
	
	srand(time(NULL));

	int randomNumber = rand();

	int randomNumberBetween0and9 = randomNumber % 10;
	int randomNumberBetween0and5 = randomNumber % 6;
	int randomNumberBetween1and6 = 1 + randomNumber % 6;
	int randomBit = randomNumber % 2;
	
	
	
	printf("randomNumber:%d randomNumberBetween0and9 :%d\n", randomNumber, randomNumberBetween0and9);

	randomNumber= rand();

	printf("randomNumber:%d\n", randomNumber);	

	
	time_t secondsBefore;
	time_t secondsAfter;
	// Stores time seconds
	int t=time(&secondsBefore);
	printf("Seconds since January 1, 1970 = %ld\n", t);
	
	for(long long int i = 0; i < 5000000000; i++) {
		//printf("%d\n", i);
		j++;
		
	}

	time(&secondsAfter);

	printf("The loop took %ld seconds \n\n\n\n\n\n", secondsAfter-t);

	printGlob();
	int j = 100; //local variable
	printf("j:%d\n", j);


	

	for (int j=0; j < 10; j++) {
		printf("%d\n", j);
	}

	
	
	
	Point p = { 1,2 };
	int a = p.x;
	int b = p.y;
	
	printf("a:%d  b:%d   a+b=%d  a-b=%d", a, b, add(a, b), sub(a, b));


}

void printGlob() {
	printf("j:%lld\n", j);
}