#include <stdio.h>
#pragma warning(disable : 4996) //This is only necessary if you're using Visual Studio

int courseAverage();
float threeAverage(float algebra, float physics, float geometry);
int main() {

	courseAverage();
	return 1;
}

int courseAverage() {

	float algebra; float physics; float geometry;

	printf("Algebra grade:");
	scanf("%f", &algebra);//&: "address of" operator, returns the memory address of variable a 

	printf("Physics grade:");
	scanf("%f", &physics);//&: "address of" operator, returns the memory address of variable a 

	printf("Geometry grade:");
	scanf("%f", &geometry);//&: "address of" operator, returns the memory address of variable a 

	printf("Algebra grade:%f, Physics grade:%f, Geometry grade:%f\n", algebra, physics, geometry);
	printf("The average is : %.8f", threeAverage(algebra,physics,geometry));

	//printf("You gave %d as input\n", a);
	//printf("10 + %d = %d", a, a+10);

	return 1;


}

float threeAverage(float algebra, float physics, float geometry) {


	return (algebra + physics + geometry) / 3.0;



}