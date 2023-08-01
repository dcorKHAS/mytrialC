#include <stdio.h>
#include <stdlib.h>


int main() {
	/*
	A Park Garage company asked you to create a program that asks if the driver is a member 
	
	*/
	char member[20000];
	char hours_string[1000];
	double hours;
	printf("Are you a member? Y/N \n");
	scanf_s("%s", member, 19);

	while (member[0]!='Y' && member[0] != 'N')
	{
		printf("Are you a member? Y/N \n");
		scanf_s("%s", member, 19);
	}
	
	printf("The user input is : %c\n", member[0]);
	printf("member == \'Y\' : %d\n", member == 'Y');

	int isValid = 0;
	
	while (isValid == 0) {

		isValid = 1;
		printf("How many hours have you parked?\n");

		scanf_s("%s", hours_string, 999);

		int haveIseenAperiod = 0;
		for (int i = 0; hours_string[i] && isValid; i++) {

			//printf("%c\n", hours_string[i]);
			if (!(hours_string[i] <= 57 && hours_string[i] >= 48)) { //if it is not in 0123456789

				if (hours_string[i] == '.' && haveIseenAperiod == 0) { //if it is not in 0123456789 and it is the first period

					haveIseenAperiod = 1;
				}
				else {

					isValid = 0;

				}

				//Is it a period  123.1414

			}
			
		}
		printf("The input %s is valid : %d\n", hours_string, isValid);
		hours = atof( hours_string);
		printf("hours is %lf\n", hours);
		float fixed_cost;
		fixed_cost = member[0] == 'Y' ? 1.5 : 3 ;

		if (hours > 3) {


			printf("The total cost is %f", fixed_cost + 4.5 + (hours - 3) * 0.5);

		}
		else if (hours > 2) {

			printf("The total cost is %f", fixed_cost + 3.5 + (hours - 2) * 1);


		}
		else if (hours > 1) {

			printf("The total cost is %f", fixed_cost + 2  + (hours - 1) * 1.5);

		}
		else {

			printf("The total cost is %f", fixed_cost + hours * 2);

		}

		//printf("You have to pay %f dollars\n", member[0] == 'Y' ? 1.5 * hours : 3 * hours);

	}
	
	//  condition ? value if true : value if false


	//printf("The value of character 9 is : %d", '9');
	//printf("The value of character 0 is : %d", '0');





	printf("You stayed for %s hours in the parking lot.", hours_string);

		
	/*	and then charge the driver 
	with 1,5$ fixed cost, if the driver is not a member the fixed cost is 3$. Make sure to keep asking until the driver 
	enters the proper response
	*/









/*
	Then asks the driver how many hours have parked. For the 1st hour the cost is 2$, for the 2nd hour the price is 
	1,5$ for the 3rd hour the price is 1$. 	From the 4th hour and after the cost is 0.5$ per hour. 
	Make sure to keep asking the driver enters a valid value.

	Finds the cost the driver has to pay and print it. Ask the user to continue the program or not.

	On exit Counts and print how many drivers payed and the total amount of earnings. Ask the user to continue the program or not.

	Create a program that:

	Reads if the driver is a member or not
	Check if the driver entered the proper response
	Charge the driver with the proper fixed cost
	Asks the driver how many hours have parked
	Check if the driver entered the proper value
	Finds how many drivers payed and the total amount of earnings
	Input: Yes(Driver is member), 6(Hours has parked), No(exit program)
	Output: "Total amount is 7,5$"
	Output: "1 Driver payed. The total earnings are 7,5$"
	ex.30
	*/

}






//The session will start at 12:05