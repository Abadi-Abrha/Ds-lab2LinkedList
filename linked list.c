#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
}*head;
// these are the function prototypes.
void createList(int n);
void traverseList();
void createandDdisplay();
 void insertNodeAtEnd(int data);
 void insertNodeAtBeginning(int data);
 void deleteFirstNode();
 void deleteLastNode();
//void deleteAtAnyPosition();


int main()

{
    int n;
    printf("Linked List Implementations.");
    printf("\nEnter 1 to create new list and display List.");
    printf("\nEnter 2 to insert at the begging and display List.");
    printf("\nEnter 3 to insert at the end and display List.");
    printf("\nEnter 4 to delete at the begging List.");
    printf("\nEnter 5 to delete at the end of List.\n");
    scanf("%d",&n);

   switch (n)
   {
       case 1: printf("Choice is 1\n");
       int f;
       printf("\nEnter the size of List.\n");
    scanf("%d",&f);
       createList(f);
       traverseList();
               break;
       case 2: printf("Choice is 2");
                 int dat;
       printf("\nEnter the data at the begging.\n");
    scanf("%d",&dat);
               insertNodeAtBeginning(dat);
               traverseList();
               break;
       case 3: printf("Choice is 3");
       int data;
       printf("\nEnter the data to be added last.\n");
    scanf("%d",&data);
               insertNodeAtEnd(data);
               traverseList();
       case 4:
           deleteFirstNode();
        break;
       case 5:
        deleteLastNode();
        break;
       default: printf("Choice other than 1, 2 and 3");
                break;
   }



    //deleteAtAnyPosition();

    return 0;
}


void deleteLastNode()
{
    struct node *toDelete, *secondLastNode;

    if(head == NULL)
    {
        printf("List is already empty.");
    }
    else
    {
        toDelete = head;
        secondLastNode = head;

        /* Traverse to the last node of the list */
        while(toDelete->next != NULL)
        {
            secondLastNode = toDelete;
            toDelete = toDelete->next;
        }

        if(toDelete == head)
        {
            head = NULL;
        }
        else
        {
            /* Disconnect link of second last node with last node */
            secondLastNode->next = NULL;
        }

        /* Delete the last node */
        free(toDelete);

        printf("SUCCESSFULLY DELETED LAST NODE OF LIST\n");
    }
}

void deleteFirstNode()
{
    struct node *toDelete;

    if(head == NULL)
    {
        printf("List is already empty.");
    }
    else
    {
        toDelete = head;
        head = head->next;

        printf("\nData deleted = %d\n", toDelete->data);

        /* Clears the memory occupied by first node*/
        free(toDelete);

        printf("SUCCESSFULLY DELETED FIRST NODE FROM LIST\n");
    }
}

void insertNodeAtBeginning(int data)
{
    struct node *newNode;

    newNode = (struct node*)malloc(sizeof(struct node));

    if(newNode == NULL)
    {
        printf("Unable to allocate memory.");
    }
    else
    {
        newNode->data = data; // Link data part
        newNode->next = head; // Link address part

        head = newNode;          // Make newNode as first node

        printf("DATA INSERTED SUCCESSFULLY\n");
    }
}


void insertNodeAtEnd(int data)
{
    struct node *newNode, *temp;

    newNode = (struct node*)malloc(sizeof(struct node));

    if(newNode == NULL)
    {
        printf("Unable to allocate memory.");
    }
    else
    {
        newNode->data = data; // Link the data part
        newNode->next = NULL;

        temp = head;

        // Traverse to the last node
        while(temp->next != NULL)
            temp = temp->next;

        temp->next = newNode; // Link address part

        printf("DATA INSERTED SUCCESSFULLY\n");
    }
}



void createList(int n)
{
    struct node *newNode, *temp;
    int data, i;

    head = (struct node *)malloc(sizeof(struct node));
    if(head == NULL)
    {
        printf("Unable to allocate memory.");
        exit(0);
    }
    printf("Enter the data of node 1: ");
    scanf("%d", &data);

    head->data = data;
    head->next = NULL;
    temp = head;
    for(i=2; i<=n; i++)
    {
        newNode = (struct node *)malloc(sizeof(struct node));
        if(newNode == NULL)
        {
            printf("Unable to allocate memory.");
            break;
        }

        printf("Enter the data of node %d: ", i);
        scanf("%d", &data);
        newNode->data = data;
        newNode->next = NULL;
        temp->next = newNode;
        temp = temp->next;
    }
}

void traverseList()
{

    struct node *temp;

    // Return if list is empty
    if(head == NULL)
    {
        printf("List is empty.");
        return;
    }

    temp = head;
    while(temp != NULL)
    {
        printf("Data = %d\n", temp->data); // Print data of current node
        temp = temp->next;                 // Move to next node
    }
}
