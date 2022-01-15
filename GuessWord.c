#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>
typedef struct TreeNode
{
    char word[100];
    struct TreeNode *left, *right;
} Tree;
// typedef struct UnknownWord
// {
//     int hints;
//     char start;
//     int indexarry[100];
//     char valuearray[100];
// }UnknownWord;
int Foundflag;
int Charcmp(char c1, char c2)
{
    if (c1 == c2 || c1 + 32 == c2 || c1 == c2 + 32)
        return 0;
    if (c1 > 96)
        c1 -= 32;
    if (c2 > 96)
        c2 -= 32;
    return c1 - c2;
}
Tree *Insert(Tree *root, char *word) // Insert word in Tree
{
    if (root == NULL)
    {
        root = (Tree *)malloc(sizeof(Tree));
        strcpy(root->word, word);
        root->left = NULL;
        root->right = NULL;
    }
    else
    {
        int res = strcmp(root->word, word);
        if (res == 0)
        {
            printf("Word alredy present");
            return NULL;
        }
        else if (res > 0)
            root->left = Insert(root->left, word);
        else
            root->right = Insert(root->right, word);
    }
    return root;
}
void Display(Tree *root)
{
    if (root)
    {
        Display(root->left);
        printf("%s,", root->word);
        Display(root->right);
    }
}
Tree *FindSubtree(Tree *root, char name) //This function finds subtree which
                                         // starts with the searching name
{
    if (root != NULL)
    {
        int Result = Charcmp(root->word[0], name);
        //   printf("%d",Result);
        if (Result == 0)
            return root;

        else if (Result < 0)
            return FindSubtree(root->right, name);

        else
            return FindSubtree(root->left, name);
    }
    return root;
}

void FindWords(Tree *root, char *word) //This function find the words in given tree
{
    if (root != NULL)
    {
        if (strlen(root->word) == strlen(word))
        {
            int ind = 0;
            if(Charcmp(word[ind],root->word[ind])!=0)
            goto Next;
            ind++;
            while(word[ind] != '\0')
            {
                if (word[ind] != '-' && word[ind] != root->word[ind]) //Checks for hints
                    goto Next;
                ind++;
            }
            printf("\nWord matches with '%s'", root->word);
            Foundflag = 1;
        }
    Next:
        FindWords(root->right, word);
        FindWords(root->left, word);
    }
}

int main()
{
    Tree *Root = NULL;
    char word[100];
    FILE *fp = fopen("Dictionary.txt", "r");
    while (!feof(fp))
    {
        fscanf(fp, "%s", word);
        Root = Insert(Root, word);
    }
    fclose(fp);
    Display(Root);
    char start;
    int length;
    char unknown[100];
    do
    {
        printf("\n'$' for exit\nEnter word to search in format of:'x--x--x' ( where 'x'->known character & '-' is unknown):");
        scanf("%s", unknown);
        if (unknown[0] == '$')
            exit(1);    
        Tree *Subtree = FindSubtree(Root, unknown[0]);
        if (Subtree != NULL)
        {
           // printf("Subtree \n");
           // Display(Subtree);
               Foundflag=0;
                FindWords(Subtree, unknown);
                if(Foundflag==0)
                    printf("Word not found");
        }
        else
            printf("Word not found");
    } while (1);
}
