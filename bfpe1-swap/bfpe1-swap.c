#include <stdio.h>
void swap(int * a, int * b);
int main()
{
       
    int a = 10; // "int" is the data type,  "a" identifier  "=" is an assignment operation  
                //"10" is a literal, everythin in green are comments
    int b = 20;

    swap(&a, &b);


    printf("hello world!\n"); // "hello world!" is a string literal (including the parantheses)
    printf("a=%d and b=%d\n", a, b); //prints "a=10 and b=20"
    
    int aOld = a; 
    a = b;
    b = aOld;
    
    printf("a=%d and b=%d\n", a, b);
    
    //int d = a + b + 10;

    //  = : assignment operation
    // lhs: left hand side --> Has to be an identifier
    // rhs: right hand side ---> Has to be a value --> It can also be an expression
    //
    
    //"a=%d and b=%d\n" : a format string
    /*
    
    
    a = b;
    b = c;
    printf("a=%d and b=%d\n", a, b);
    */

}
void swap(int* a, int* b) {

    int temp;
    temp = *a;
    *a = *b;
    *b = temp;


}