#include <stdio.h>
#include <string.h>
int main() {
	//Ask the user whether the last flip is head or tails?
	//3. option "stop" input===> stop asking for flips
		//We do not know how many coin flips there will be in the beginning
		// There will be an input every time the coin is flipped ---> in every iteration
	//There will be a loop and the user will provide input INSIDE the loop

	
	
	int headsCount = 0;//Can only be used in the main function
	int tailsCount = 0;
	char  inputString[10];




	while (strcmp(inputString, "stop") != 0)

	{
		
		printf("Please enter head/tails:\n");
		scanf_s("%s",inputString,sizeof(inputString));
		//printf("The input is %s\n", inputString);
		//printf("inputString != stop : %d\n", inputString != "stop");
		//printf("strcmp(inputString, stop): %d\n", strcmp(inputString, "stop"));
		if ( strcmp(inputString , "head") == 0) {

			//increase the heads count variable
			headsCount++;


		}
		else if (strcmp(inputString, "tails") == 0)
			


			{

				tailsCount++;
				//increase the tail count variable



			}
			


		//end of block return to condition
	}

	//We move here if the last input is "stop"

	// for is more popular


	//YOU CAN DO ANYTHING with either loops









	//4. option









	printf("Head won %d times and tails won %d times", headsCount, tailsCount);

	return 0;



}
