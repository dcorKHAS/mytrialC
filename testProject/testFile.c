#include <stdio.h>
#pragma warning(suppress : 4996)
#define Ask_Numbers(numbers) do { \
    printf("Enter 10 integer numbers:\n"); \
    for (int i = 0; i < 10; i++) { \
        printf("Number %d: ", i + 1); \
        scanf_s("%d", &numbers[i],10); \
    } \
} while (0)
     void calculateTheDayofTheweek(int day) {
         //takes int input from user prints the day of the week
printf("Enter the day of the month: ");
scanf_s("%d", &day);
if (day < 1 || day > 31) {
    printf("Invalid day of the month");
}
else {
	switch (day % 7) {
	case 0:
		printf("Sunday");
		break;
	case 1:
		printf("Monday");
		break;
	case 2:
		printf("Tuesday");
		break;
	case 3:
		printf("Wednesday");
		break;
	case 4:
		printf("Thursday");
		break;
	case 5:
		printf("Friday");
		break;
	case 6:
		printf("Saturday");
		break;
	}

	 }
     //test for the above function
int main() {//some values for testing calculateTheDayofthe week
    int day = 0;
	int dayoftheweek = 0;
	dayoftheweek = calculateTheDayofTheweek(day);
	printf("The day of the week is %d", dayoftheweek);
	return 0;
}


