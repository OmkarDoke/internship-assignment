#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int CheckPalindrome(char *str)
{
    int len = strlen(str);
    for (int i = 0; i <= len / 2; i++)
        if (str[i] != str[len - i - 1])
            return 0;

    return 1;
}
int main()
{
    char String[1000];
    printf("Enter the String:");
    scanf("%s",String);
    if (CheckPalindrome(String))
        printf("String \'%s\' is palindrome", String);
    else
        printf("String\'%s\' is not palindrome", String);
}
