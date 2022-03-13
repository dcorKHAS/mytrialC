#include <stdio.h>
#include <stdlib.h>
int main(void) {
	if (puts("Hello, world!") == EOF) {
		return EXIT_FAILURE;
		// code here never executes
	}
	char str[21];
	for (unsigned int i = 0; i < 20; ++i) {
		 str[i] = '0' + i;
	}
	str[20] = '\0';
	printf("%s", str);
	return EXIT_SUCCESS;
	// code here never executes
}