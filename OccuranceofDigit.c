#include<stdio.h>
void CountDigit(int countarray[])
{
    long int number;
    printf("Enter a number:");
    scanf("%ld",&number);
    if(number<0)
    number*=-1;
    while (number)
    {
        countarray[(number%10)]++;
        number/=10;
    }
}
int main()
{
    int countarray[10];
    for(int i=0;i<10;i++)
    countarray[i]=0;

    CountDigit(countarray);
    printf("Digit   Frequency\n");
    for(int i=0;i<10;i++)
    {
        printf("%d\t%d\n",i,countarray[i]);
    }

}
