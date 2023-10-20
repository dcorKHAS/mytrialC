
//extern int j = 0;//global variable

int add(int a, int b) {

	static int k=0;//local variable
	//if you want to avoid a local variable to be destroyed after the function call, you can use the static keyword
	
	k++;
	printf("The add function is called for the %d. time\n", k);
	return  a + b;

}

int sub(int a, int b) {


	return a - b;

}
