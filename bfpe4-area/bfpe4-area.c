#include <stdio.h>
#pragma warning(disable : 4996) //This is only necessary if you're using Visual Studio
int main() {

	float length, width;

	printf("Length:");
	scanf("%f", &length);//&: "address of" operator, returns the memory address of variable a 

	printf("Width:");
	scanf("%f", &width);//&: "address of" operator, returns the memory address of variable a 

	printf("Length:%f, Width:%f\n", length, width);
	printf("The area is : %.2f", width*length);




	return 1;
}