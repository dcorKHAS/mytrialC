#include <stdio.h>

int main() {

	int a, b;
	a = (10==16);
	b = -2;
	
	a = 14;
	for (; a > 0; a >>= 1) {

		printf("%d", a % 2);

	}
	printf("\n");

	printf("a:%d b:%d a && b: %d\n", a, b, a && b);
	printf("a:%d b:%d a || b: %d\n", a, b, a || b);
	printf("a:%d b:%d !a:%d  !b: %d\n", a, b, !a, !b);
	//Truthy  and falsy values

	//a[b] return the b'th element of a
	char* myString = "Hello";
	printf("%s\n", myString);
	printf("%c\n", myString[a+1]);
	

	/*
	printf("a:%d b:%d a & b: %d\n", a, b, a & b); // ~ is the complement operator
	printf("a:%d b:%d a | b: %d\n", a, b, a | b);
	printf("a:%d b:%d a ^ b: %d\n", a, b, a ^ b);
	printf("a:%d b:%d a>>2:%d b<<2: %d\n", a, b, a>>2, b<<2);
	*/
// Bitwise operator
	// ~ complement: flip every bit of the operand   a=101010101 ===> ~a= 010101010
	//2's complement notation ===>   if a is positive -a  ==> ~a+1
	// a =10   a = 1010   b=9    b=1001   a & b = 1000  a | b= 1011 11  a ^ b = 0011
	//a =10   a = 0000000000000001010    a >> 1 = 000000000000101  a >> 2 = 000000000010 a>>3 = 0000000001 a>>4=0000
	// a = 10  a = 0000000000000001010    a<<1 = 0000000000000010100  a<<2 =0000000000000101000
	
	return 1;





}