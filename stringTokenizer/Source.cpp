/* strtok example */
#include <stdio.h>
#include <string.h>

int main()
{
    char str[] = "- This, a sample,\n, string.";
    char* pch;
    printf("Splitting string \"%s\" into tokens:\n", str);
    pch = strtok(str, " ,.-");
    while (pch != NULL)
    {
        printf("%s\n", pch);
        pch = strtok(NULL, " ,.-");
        

    }
    return 0;
}
size_t strlen2(const char* str) {
    const char * s;
    for (s = str; *s; ++s) {}
    return s - str;
}