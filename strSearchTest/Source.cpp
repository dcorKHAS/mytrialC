#include <stdio.h>
#include <string.h>

#define SIZE 40

int main(void)
{
    char buffer1[SIZE] = "computer program";
    char* ptr;
    int    ch = 'p';
    printf("The first occurrence of %c in  is \n",buffer1[1]);
    buffer1[9] = 'l';
    printf("The first occurrence of %c in  is \n", buffer1[1]);
    ptr = strchr(buffer1, ch);
    printf("The first occurrence of %c in '%s' is '%s'\n",
        ch, buffer1, ptr);

}