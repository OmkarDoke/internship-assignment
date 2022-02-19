#include<stdio.h>
int CountDigit(long int num)
{
    int count=0;
    if(num==0)
    return 1;
    while(num)
    {
        count++;
        num/=10;
    }
    return count;
}
int main()
{
    long int number;
    printf("Enter a number:");
    scanf("%ld",&number);
    printf("Total number of digit's =%d\n",CountDigit(number));
}