#include <stdio.h>

int main() {
	float wikiUsage, memeUsage; //declaration of variables
	float WIKI_RATE = 0.10;
	float MEME_RATE = 0.05;
	printf("Wiki usage in Mb:\n");
	scanf_s("%f", &wikiUsage); // & operator --> address of wikiUsage variable
	printf("Meme usage in Mb:\n");
	scanf_s("%f", &memeUsage);

	printf("wikiUsage:%.2f memeUsage:%.2f \n", wikiUsage, memeUsage);

	float totalConsumption = wikiUsage * WIKI_RATE + memeUsage * MEME_RATE; //Magic numbers 

	if ( totalConsumption >= 100  ) {
	
		printf("Too much consumption\n");
		printf("I can add a second message here");
	}
	else {

		printf("That's a reasonable amount of consumption\n");

	}

	if (wikiUsage * WIKI_RATE < memeUsage * MEME_RATE) {

		printf("WOW MANY MEMES\n");
		printf("SUCH LOL\n");
	}
	printf("This is printed after the if block\n");

	return 1;
}