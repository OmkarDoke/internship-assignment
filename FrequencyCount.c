#include<stdio.h>
#include<string.h>
#include<malloc.h>
typedef struct List{
    char Word[100];
    int count;
    struct List *next;

}WordList;


void CheckandAdd(WordList *Head,char *word)
{
    WordList *prev=Head,*curr=Head->next;
    while (curr!=NULL)
    {
        if(strcmp(curr->Word,word)==0)
        break;
        prev=curr;
        curr=curr->next;
    }
    if(curr!=NULL)
    {
        curr->count++;
    }
    else
    {


        
        WordList *new=(WordList *)malloc(sizeof(WordList));
        new->next=NULL;

        strcpy(new->Word,word);
        new->count=1;
        prev->next=new;
        Head->count++;
    }

}

void ShowFrequency(WordList *Head)
{
    printf("Total word's are:%d\nWord\t count\n",Head->count);
    WordList *curr=Head->next;
    while (curr)
    {
        printf("%s \t%d\n",curr->Word,curr->count);
        curr=curr->next;
    }
    

}
int main()
{
    char input[1000000];
    printf("Enter a paragraph:");
    scanf("%[^\n]*c",input);
    char *word;
    WordList *Head=(WordList *)malloc(sizeof(WordList));
    Head->count=0;
    Head->next=NULL;
    word=strtok(input," ");
    while (word)
    {
        CheckandAdd(Head,word);
        // printf("%s\n",tokan);
        word=strtok(NULL," ");

    }    
    ShowFrequency(Head);  
}