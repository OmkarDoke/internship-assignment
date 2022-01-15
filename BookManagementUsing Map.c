#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <stdlib.h>
typedef struct Book
{
    int Book_id;
    char name[100];
    struct Book *next;
} Book;
Book BookList[26];
void Init()
{
    for (int i = 0; i < 26; i++)
    {
        BookList[i].next = NULL;
    }
}
int GetIndex(char ch)
{
    if (ch > 96)
        return ch - 97;
    else
        return ch - 65;
}



int SearchBookbyName(char *name)
{

    
    int index = GetIndex(name[0]);
    if (BookList[index].next == NULL)
        return 0;
    else
    {
        Book *curr = BookList[index].next;
        while (curr != NULL)
        {
            if (strcmp(name, curr->name) == 0)
                break;
            curr = curr->next;
        }
        if (curr == NULL)
            return 0;
        return 1;
    }
}

void InsertBook(int id, char *name)
{
    //char name[100];

    if (SearchBookbyName(name))
    {
        printf("Book name alredy present");
    }
    else
    {
        Book *new = (Book *)malloc(sizeof(Book));
        new->Book_id = id;
        strcpy(new->name, name);
        new->next = NULL;
        int index = GetIndex(new->name[0]);
        // printf("%d",ind);
        if (BookList[index].next == NULL)
        {
            BookList[index].next = new;
        }
        else
        {
            Book *curr = BookList[index].next;
            while (curr->next != NULL)
                curr = curr->next;
            curr->next = new;
        }
        printf("Book '%s' is Added", new->name);
    }
}

void DisplayBook()
{
    for (int i = 0; i < 26; i++)
    {
        Book *curr = BookList[i].next;
        while (curr)
        {
            printf("(%s: %d)", curr->name, curr->Book_id);
            curr = curr->next;
        }
        //printf("\n");
    }
}

int DeleteBook()
{
    char name[100];
    printf("Enter Book name:");
    scanf("%s", name);
    int index = GetIndex(name[0]);
    if (BookList[index].next == NULL)
        return 0;

    else
    {
        Book *prev , *curr;
        curr = BookList[index].next;
        prev = &(BookList[index]);
        while (curr != NULL)
        {
            if (strcmp(name, curr->name) == 0)
                break;
            prev = curr;
            curr = curr->next;
        }

        if (curr == NULL)
            return 0;
       
        prev->next=curr->next;
        free(curr);
        return 1;
    }
}

int main()
{
    Init();
    int choice, option, position, id;
    char name[100];
    do
    {
        printf("\n1]Insert\t2]Delete\t3]Display\t4]Search\t5]Exit\n->");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:

            printf("Enter Book number and Book name:");
            scanf("%d %s", &id,name);
            InsertBook(id,name);

            break;
        case 2:
            if (DeleteBook())
                printf("Book is deleted");
            else
                printf("Book not found");

            break;
        case 3:
            DisplayBook();
            break;
        case 4:
            printf("Enter Book name:");
            scanf("%s", name);
            if (SearchBookbyName(name))
                printf("Book found");
            else
                printf("Book not found");

            break;
        case 5:
            exit(0);

        default:
            printf("Invalid choice");
            break;
        }
    } while (1);
}
