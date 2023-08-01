#include <stdio.h>
#pragma warning(disable : 4996) //This is only necessary if you're using Visual Studio


int areaRectangle();
float calculateArea(float length, float width);



int main() {

	areaRectangle();
	//printf("%f %f", length, width);
	return 1;
}


int areaRectangle() {


	float length, width;
	printf("&Length: %p\n",&length);
	printf("Length:");
	scanf("%f", &length);//&: "address of" operator, returns the memory address of variable a 

	printf("Width:");
	scanf("%f", &width);//&: "address of" operator, returns the memory address of variable a 

	
	printf("The area is : %.2f", calculateArea(length, width ));

	return 1;

}
float calculateArea(float length, float width) {
	printf("Length:%f, Width:%f\n", length, width);

	return width * length;

}


