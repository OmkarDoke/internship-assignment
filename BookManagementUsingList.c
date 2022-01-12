#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
typedef struct Book
{
    int Book_id;
    char *Book_name;
    struct Book *next;
} Book;
int InsertBook(Book *Head, int position)
{
    Book *curr = Head->next;
    Book *prev = Head;
    int no;
    char name[100];
    printf("Enter Book name and Book id:");
    scanf("%s %d", name, &no);
    Book *new = (Book *)malloc(sizeof(Book));
    new->Book_id = no;
    new->next = NULL;
    new->Book_name = (char *)malloc(strlen(name) * sizeof(char));
    while (position > 1)
    {
        prev = curr;
        curr = curr->next;
        position--;
    }
    strcpy(new->Book_name, name);
    prev->next = new;
    new->next = curr;
    printf("Book is added");
    Head->Book_id++;
}

void DisplayBook(Book *Head)
{
    printf("Available books are:\n");
    Book *curr = Head->next;
    if (curr == NULL)
    {
        printf("List is empty");
        return;
    }
    while (curr)
    {
        printf("(%d:%s)", curr->Book_id, curr->Book_name);
        curr = curr->next;
    }
}
void DeleteBook(Book *Head, int position)
{
    Book *curr = Head->next;
    Book *prev = Head;
    while (position > 1)
    {
        prev = curr;
        curr = curr->next;
        position--;
    }
    if (curr == NULL)
        prev->next = NULL;
    else
        prev->next = curr->next;
    free(curr);
    printf("Record is deleted");
    Head->Book_id--;
}
int SearchbyId(Book *Head)
{
    Book *curr = Head->next;
    int position = 1, id;
    printf("Enter Book id:");
    scanf("%d", &id);
    while (curr)
    {
        if (curr->Book_id == id)
            return position;
        position++;
        curr = curr->next;
    }
    return 0;
}

int SearchbyName(Book *Head)
{
    Book *curr = Head->next;
    int position = 1, id;
    char name[100];
    printf("Enter Book name:");
    scanf("%s",name);
    while (curr)
    {
        if (strcmp(curr->Book_name,name) == 0)
            return position;
        position++;
        curr = curr->next;
    }
    return 0;
}
int main()
{
    Book *Head = (Book *)malloc(sizeof(Book));
    Head->Book_id = 0; // To store the count of books in the list
    Head->next = NULL;
    int choice, option, position, result;
    do
    {
        printf("\n1]Insert\n2]Delete\n3]Display\n4]Search\n5]Exit\n->");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter position:");
            scanf("%d", &position);
            if (position > Head->Book_id + 1 && position < 1)
                printf("Invalid position");

            else
                InsertBook(Head, position);

            break;
        case 2:
            printf("Enter position:");
            scanf("%d", &position);
            if (position <= Head->Book_id && position > 0)
                DeleteBook(Head, position);
            else
                printf("Invalid position");

            break;
        case 3:
            DisplayBook(Head);
            break;
        case 4:
            printf("1]Search By id\t 2]Search by Name:\n-?");
            scanf("%d", &option);
            result = -1;
            if (option == 1)
                result = SearchbyId(Head);
            else if (option == 2)
                result = SearchbyName(Head);
            if (result == -1)
                printf("Invalid choice");
            else if (result == 0)
                printf("Book not found");
            else
                printf("Book found at position %d", result);

            break;
        case 5:
            exit(0);

        default:
            printf("Invalid choice");
            break;
        }

    } while (1);
}