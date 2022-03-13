#include <stdio.h>
void main(void){
int i=1;
int j=2;
int k=3;
printf("%d %d %d \n",i,j,k);	
k=(i=j);
printf("%d %d %d",i,j,k);}	
