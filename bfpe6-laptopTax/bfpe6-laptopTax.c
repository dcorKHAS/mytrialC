#include <stdio.h>
#pragma warning(disable : 4996) //This is only necessary if you're using Visual Studio

int laptopTax();
float calculateTax(float price, float rate);
int main() {

	
	laptopTax();
	return 1;
}

int laptopTax() {

	float price, taxRate;

	printf("Laptop price:");
	scanf("%f", &price);//&: "address of" operator, returns the memory address of variable a 

	printf("Tax rate:");
	scanf("%f", &taxRate);//&: "address of" operator, returns the memory address of variable a 

	printf("Laptop price:%f, Tax rate:%f\n", price, taxRate);
	printf("The tax included price is : %.2f",price + calculateTax(price, taxRate));
	//printf("The tax included price is : %.2f", price * (taxRate + 100.0) / 100.0);


}

float calculateTax(float price, float rate) {

	return (price * (rate / 100.0));


}