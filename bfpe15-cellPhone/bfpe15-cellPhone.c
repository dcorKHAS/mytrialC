#include <stdio.h>


int main() {

	float  usage; //declaration of variables
	float RATE_1_500 = 0.010;
	float RATE_501_800 = 0.008;
	float RATE_800plus = 0.005;
	float usage;
	float usage_1_500 = usage>500 ? 500 : usage;
	float usage_501_800 = usage > 500 && usage < 801 ? usage - 500 : (usage>800?300:0);
	float usage_800plus = usage > 800  ? usage - 800 : 0;

	float bill= usage_1_500 * RATE_1_500;

	printf("Wiki usage in Mb:\n");
	scanf_s("%f", &wikiUsage); // & operator --> address of wikiUsage variable
	printf("Meme usage in Mb:\n");
	scanf_s("%f", &memeUsage);



}