#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
//dodaje na tail, usuwam tail

typedef struct lista
{
    int val;
    struct lista *next;
    struct lista *prev;

}lista;

void addElement(struct lista** head,struct lista** tail, int n)
{
    lista *newElem = NULL;
    newElem = (lista*)malloc(sizeof(lista));
    newElem->val = n;
    newElem->next = NULL;
    if((*head) == NULL) // jesli lista jest pusta
    {
        (*head) = newElem;
        (*tail) = newElem;
        newElem->next = NULL;
        newElem->prev = NULL;
    }
    else
    {
       (*tail)->next = newElem;
       newElem->prev = (*tail);
       (*tail) = newElem;
    }
}

void popElement(struct lista** head,struct lista** tail)
{
    if((*head) == NULL) //jesli lista jest pusta
    {
        printf("Queue is empty!\n");
        return;
    }
    if((*head) == (*tail))
    {
        free((*head));
        (*head) = NULL;
        (*tail) = NULL;
    }
    else
    {
        lista *temp = NULL;
        temp = (lista*)malloc(sizeof(lista));
        temp = (*tail);
        (*tail) = temp->prev;
        (*tail)->next = NULL;
        temp->prev = NULL;
        free(temp);
    }
}

void printList(struct lista** head)
{
    lista *temp = NULL;
    temp = (lista*)malloc(sizeof(lista));
    temp = (*head);
    if((*head) == NULL)
    {
        printf("Queue is empty!\n");
        return;
    }
    while(temp)
    {
        printf("%d ", temp->val);
        temp = temp->next;
    }
    printf("\n ");
}
int main()
{
    lista *head = NULL;
    lista *tail = NULL;
    int loop=1;
    int n;
    int choice;
    do{

        printf("Menu\n");
        printf("[1] Add element\n");
        printf("[2] Remove element\n");
        printf("[3] Print Queue\n");
        printf("[0] End program\n");
        printf("Choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
            {
                printf("Give number: ");
                scanf("%d",&n);
                addElement(&head, &tail, n);
                system("cls");
                break;
            }
            case 2:
            {
                system("cls");
                popElement(&head, &tail);
                break;
            }
            case 3:
            {
                system("cls");
                printList(&head);
                break;
            }
            case 0:
            {
                loop = 0;
                break;
            }
        }

    }while(loop);

    return 0;
}
