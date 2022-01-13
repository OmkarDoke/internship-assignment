#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>
typedef struct TreeNode
{
    char word[100];
    struct TreeNode *left, *right;
} Tree;

int Foundflag;
Tree *Insert(Tree *root, char *word)// Insert word in Tree
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
Tree *FindSubtree(Tree *root, char name)  //This function finds subtree which
                                            // starts with the searching name
{                                            
    if (root != NULL)
    {
        if (root->word[0] == name)
            return root;

        else if (root->word[0] < name)
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
                for(int i = 0;word[i]!='\0';i++)
                {
                    if(word[i]!='-' && word[i]!=root->word[i])  //Checks for hints
                    goto Next;
                }
               printf("\nWord matches with '%s'", root->word);
               Foundflag=1;
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
    //Display(Root);
    char start;
    int length;
    char unknown[100];
    do
    {
        printf("\n'$' for exit\nEnter word to search in format of:'x--x--x' ( where 'x'->known character & '-' is unknown):");
        scanf("%s", unknown);
        if(unknown[0]=='$')
        exit(1);
        Tree *Subtree = FindSubtree(Root, unknown[0]); 
        if (Subtree != NULL)
        {
            //printf("Subtree \n");
           //Display(Subtree);
           Foundflag=0;
            FindWords(Subtree, unknown);
            if(Foundflag==0)
                printf("Word not found");
        }
        else
            printf("Word not found");
    } while (1);
}
