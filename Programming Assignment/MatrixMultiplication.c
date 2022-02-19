#include<stdio.h>
void Accept(int m[][100],int *row,int *col)
{   
    int r,c;
    printf("Enter size(row & column):");
    scanf("%d %d",&r,&c);
    *row=r;
    *col=c;
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        scanf("%d",&m[i][j]);
    }
}
void Display(int m[][100],int row,int col)
{
  for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        printf("%d ",m[i][j]);
        printf("\n");
    }
 
}
void Multiply(int m1[][100],int row1,int col1,int m2[][100],int row2,int col2,int m3[][100])
{
    for(int i=0;i<row1;i++)
    {
        for(int j=0;j<col2;j++)
        {
            for(int k=0;k<col1;k++)
            m3[i][j]+=m1[i][k]*m2[k][j];
        }
    }
}
int main()
{
    int r1,c1,r2,c2,M1[100][100],M2[100][100],M3[100][100];
    printf("For matrix M1\n");
    Accept(M1,&r1,&c1);
   // Display(M1,r1,c1);
   printf("For matrix M2\n");
    Accept(M2,&r2,&c2);
    if(c1==r2)
    {
    Multiply(M1,r1,r2,M2,r2,c2,M3);
    Display(M3,r1,c2);
    }
    else
    printf("Multiplication not possible ");
}