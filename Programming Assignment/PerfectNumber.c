#include<stdio.h>
#include<stdlib.h>
int isPerfect(int num)
{
    int factorsum=0;
    for(int i=1;i<num-1;i++)
    {
        if(num%i==0)
        factorsum+=i;
    }
    return factorsum==num;
}
int main()
{
     int number;
    printf("Enter a number:");
    scanf("%d",&number);
    if(number<6)
    {
        printf("Invalide range");
        exit(1);

    }
    printf("Perfect numbers from 1 to %d are:\n",number);
    for(int i=6;i<=number;i++)
    {
        if(isPerfect(i))
        printf("%d\n",i);
    }
}