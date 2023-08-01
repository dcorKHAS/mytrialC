#include <stdio.h>
#include "exampleFunctions.h"
int square(int inputNumber); //function declaration
float  averageOf2(float number1, float number2);//function declaration
float averageOf3(int number1, int number2, int number3);
void swap(int * x, int * y);

int main() {

	int x, y;

	x = 10;
	y = 20;

	swap(&x, &y);
	printf("x:%d y:%d\n", x, y);




	int returnValue = square(5);

	printf("The square  function returns: %d\n", square(5));

	float  returnValue2 = averageOf2(13.0, 4.0);
	printf("The averageOf2 function returns: %f\n", returnValue2);

	returnValue2 = averageOf3(13.0, 4.0, 7.0);
	printf("The averageOf3 function returns: %f\n", returnValue2);
	// square(5) is referred as a "function call"   we have "invoked" the square function

	return 1;


}

int square(int inputNumber)  //The function signature : Return type, input parameters (types)
{
	int returnValue = inputNumber * inputNumber;

	//Function body

	printf("This will be printed every time the function is called");

	return returnValue;

	printf("This will never be printed");

	//The lines after the return statement are never
}//function definition
float  averageOf2(float number1, float number2) {
	float returnValue= (float)(number1 + number2) / 2.0;
	printf("returnvalue is  %f\n", returnValue);
	return returnValue;



}

float averageOf3(int number1, int number2, int number3) {


	return (float)(number1 + number2 + number3) / 3;
}


void swap(int* x, int* y) {

		int temp ;
		temp = *x;
		*x = *y;
		*y = temp;
		
	}
