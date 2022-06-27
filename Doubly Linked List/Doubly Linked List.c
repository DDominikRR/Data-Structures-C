#include <stdlib.h>
#include <stdio.h>
#include <windows.h>


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
    newElem->prev = NULL;
    if((*head) == NULL) // jesli lista jest pusta
    {
        (*head) = newElem;
        (*tail) = newElem;
        newElem->next = NULL;
        newElem->prev = NULL;
    }
    else
    {
        if(newElem->val < (*head)->val) //dodawanie najmniejszej -> przed poczatkiem
        {
            newElem->next = (*head);
            (*head)->prev = newElem;
            (*head) = newElem;
        }
        else if(newElem->val >= (*tail)->val) // dodawanie najwiekszej ->za koncem
        {
            newElem->prev = (*tail);
            (*tail)->next = newElem;
            newElem->next = NULL;
            (*tail) = newElem;
        }
        else    //dodawanie miedzy dwoma elementami
        {
            lista *temp;
            temp = (lista*)malloc(sizeof(lista));
            temp = (*tail)->prev;

            while(temp)
            {
                if(newElem->val >= temp->val)
                {
                    newElem->next = (temp->next);
                    (newElem->next)->prev = newElem;
                    newElem->prev = temp;
                    temp->next = newElem;
                    break;
                }
                else
                {
                    temp = temp->prev;
                }
            }
        }
    }
}

void findElement(struct lista** head,struct lista** tail, int n)
{
    lista *temp = NULL;
    temp = (lista*)malloc(sizeof(lista));
    temp = (*head);
    if((*head) == NULL)
    {
        printf("List is empty!\n");
        return;
    }
    while(temp)
    {
        if(temp->val == n)
        {
            printf("Address: %d\n", temp);
            temp = NULL;
            break;
        }
        else
        {
            if(temp == (*tail)) //jak na ostatnim tego nie ma, to nie ma w liscie
            {
                printf("Element is not in the list!\n");
            }
            temp = temp->next;
        }
    }
}

void popElement(struct lista** head,struct lista** tail, int n)
{
    if((*head) == NULL) //jesli lista jest pusta
    {
        printf("List is empty!\n");
        return;
    }
    lista *temp = NULL;
    temp = (lista*)malloc(sizeof(lista));
    temp = (*head);

        while(temp)
        {
            if(temp->val == n) // czy temp to n
            {
                if(temp == (*head) && temp == (*tail)) //jesli element jest jedyny
                {
                    free(temp);
                    (*tail) = NULL;
                    (*head) = NULL;
                    return;
                }
                else if(temp == (*head))   //jesli element jest poczatkiem
                {
                    (*head) = temp->next;
                    (*head)->prev = NULL;
                    free(temp);
                    return;
                }
                else if(temp == (*tail)) //jesli element jest ostatni
                {
                    (*tail) = temp->prev;
                    (*tail)->next = NULL;
                    free(temp);
                    return;
                }
                else //jesli element jest w sordku
                {
                (temp->prev)->next = temp->next;
                (temp->next)->prev = temp->prev;

                free(temp);
                return;
                }
            }
            else //jesli nie znaleziono elementu
            {
                if(temp == (*tail)) //jak na ostatnim tego nie ma, to nie ma w liscie
                {
                    printf("Element is not in the list!\n");
                }
                temp = temp->next;
            }
        }


}

void printList(struct lista** head)
{
    lista *temp = NULL;
    temp = (lista*)malloc(sizeof(lista));
    temp = (*head);
    if((*head) == NULL)
    {
        printf("List is empty!\n");
        return;
    }
    while(temp)
    {
        printf("%d ",temp->val);
        temp = temp->next;
    }
    printf(" \n");
}
int main()
{
    lista *head = NULL;
    lista *tail = NULL;
    int loop=1;
    int n;
    int choice;
    do{

        printf("Menu:\n ");
        printf("[1] Add element\n ");
        printf("[2] Find element\n ");
        printf("[3] Remove element\n ");
        printf("[4] Print list\n ");
        printf("[0] End program\n ");
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
                printf("Specify element to find ");
                scanf("%d",&n);
                findElement(&head, &tail, n);
                break;
            }
            case 3:
            {
                system("cls");
                printf("Specify the element to remove ");
                scanf("%d",&n);
                popElement(&head, &tail, n);
                break;
            }
            case 4:
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
