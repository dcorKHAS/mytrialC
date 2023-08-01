#include <stdio.h>
void main(void){
char str[11];

for (unsigned int i = 0; i < 10; ++i) {
str[i] = '0' + i;
}
str[10] = '\0';
printf("%d, %d, %d", '1' , str[5], str[0]);
}
