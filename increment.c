#include <stdio.h>
static unsigned int counter=0;
void increment(void) {
//static unsigned int counter = 0;
counter++;
printf("%d ", counter);
}

int retrieve(void){
 return counter;
}

int main(void) {
for (int i = 0; i < 5; i++) {
   increment();
   printf("Retrieve returns %d \n",retrieve());
}
return 0;
}

