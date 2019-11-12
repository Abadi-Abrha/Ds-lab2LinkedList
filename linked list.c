#include<stdio.h>
#include <stdlib.h>



struct node {
    int data;
    struct node * next;
}*head, *last;

struct node *current = NULL;
void createList(int a);
void displayList();
void insertAtBeginning(int b);
void insertAtEnd(int c);
void insertAtN(int d, int e);
void deleteFromBeginning();
void deleteFromEnd();
void deleteFromN(int f);

int main(){

	int s,j=2,r;
	int n, data, position;
	    printf("\nDs-Lab-2\n 1.Abadi abrha\n 2.Kibrom Mekonnen\n 3.Misgina G/tsadik\n");
	do{ printf("\n______________________________________________\n");
		printf(" Enter  1 to create List");
		printf("\n \t2 to add item at the begginning ");
		printf("\n \t3 to add item at the end(last)");
		printf("\n \t4 to add item at the middle");
		printf("\n \t5 to delete item at the begginning ");
		printf("\n \t6 to delete item at the end(last) ");
		printf("\n \t7 delete item at the middle ");
		printf("\n \t8 to search an item ");
		printf("\n_____________________________________\n");
		scanf("%d",&s);
	switch(s)
    {case 1:
	    	printf("Enter the total number of nodes in list: ");
            scanf("%d", &n);
            createList(n);
            printf("\nData in the list \n");
    		displayList();
            break;
	    case 2:
	    	printf("Enter data of first node : ");
            scanf("%d", &data);
            insertAtBeginning(data);
            printf("\nData in the list \n");
    		displayList();
            break;
	    case 3:
	    	printf("Enter data of last node : ");
            scanf("%d", &data);
            insertAtEnd(data);
            printf("\nData in the list \n");
    		displayList();
            break;
	    case 4:
	  		printf("Enter the position : ");
            scanf("%d", &n);
            printf("Enter data of %d node : ", n);
            scanf("%d", &data);
            insertAtN(data, n);
            printf("\nData in the list \n");
    		displayList();
            break;
	    case 5:
		    deleteFromBeginning();
		    printf("\nData in the list \n");
    		displayList();
		    break;
	    case 6:
		    deleteFromEnd();
		    printf("\nData in the list \n");
    		displayList();
		    break;
	    case 7:
		    printf("Enter the node position which you want to delete: ");
            scanf("%d", &n);
            deleteFromN(n);
    		printf("\nData in the list \n");
    		displayList();
		    break;
		case 8:
		    printf("Enter the item you want to search: ");
            scanf("%d", &n);
            search(n);
    		printf("\nData in the list \n");
    		displayList();
		    break;
	    default:
	    	printf("no such number is needed here please enter from 1 to 8");
    }j = 1;
printf("\nif you want to continue press num>0 else press 0:");
scanf("%d",&r);
}while(j<=r);

}
void createList(int n)
{int i, data;
    struct node *newNode;
    if(n >= 1)
    {head = (struct node *)malloc(sizeof(struct node));
        printf("Enter data of 1 node: ");
        scanf("%d", &data);
        head->data = data;
        head->next = NULL;
        last = head;
  for(i=2; i<=n; i++)
        {
            newNode = (struct node *)malloc(sizeof(struct node));
            printf("Enter data of %d node: ", i);
            scanf("%d", &data);
            newNode->data = data;
            newNode->next = NULL;
        last->next = newNode;
        last = newNode;
        }
        printf("\nLinkd list created successfully\n");
    }}

void displayList()
{
    struct node * temp;
    int n = 1;
    if(head == NULL)
    {
printf("List is empty.\n");
    }
    else
    {temp = head;
        printf("DATA IN THE LIST:\n");

        while(temp != NULL)
        {
            printf("DATA of %d node = %d\n", n, temp->data);
            n++;
            temp = temp->next;
        }
    }
}


void insertAtBeginning(int data)
{
    struct node * newNode;
    if(head == NULL)
    {
        printf("Error, List is Empty!\n");
    }
    else
    {
        newNode = (struct node *)malloc(sizeof(struct node));
        newNode->data = data;
        newNode->next = head;
        head = newNode;

        printf("data inserted success fully\n");
    }
}

void insertAtEnd(int data)
{
    struct node * newNode;
    if(last == NULL)
    {
printf("Error, List is empty!\n");
    }
    else
    { newNode = (struct node *)malloc(sizeof(struct node));
        newNode->data = data;
        newNode->next = NULL;
        last->next = newNode;
        last = newNode;

        printf("inserted at the end\n");
    }
}

void insertAtN(int data, int p)
{
    int i;
    struct node * newNode, *temp;
    if(head == NULL)
    {
    printf("Error, List is empty!\n");
    }
    else
    {
        temp = head;
        i=1;
        while(i<p-1 && temp!=NULL)
        {
        temp = temp->next;
            i++;
        }

        if(p == 1)
        {
        insertAtBeginning(data);
        }
        else if(temp == last)
        {
            insertAtEnd(data);
        }
        else if(temp!=NULL)
        {
            newNode = (struct node *)malloc(sizeof(struct node));

            newNode->data = data;
            newNode->next = temp->next;
            temp->next = newNode;
      printf("insert at end success fully\n", p);
        }
        else
        {
            printf("Error, Invalid position\n");
        }
    }
}



void deleteFromBeginning()
{
    struct node * toDelete;

    if(head == NULL)
    {
        printf("Unable to delete. List is empty.\n");
    }
    else
    {
        toDelete = head;
        head = head->next;
        free(toDelete);
        printf("DEleted successfullyAt beginning.\n");
    }
}



void deleteFromEnd()
{
    struct node * toDelete;
    if(last == NULL)
    {
    printf("Unable to delete. List is empty.\n");
    }
    else
    {
        toDelete = last;
        if (last != NULL)
            last->next = NULL;
        free(toDelete);
        printf("deleted from end.\n");
    }
}



void deleteFromN(int position)
{struct node *current;
    int i;
    current = head;
    for(i=1; i<position && current!=NULL; i++)
    {
    current = current->next;
    }
    if(position == 1)
    {
    deleteFromBeginning();
    }else if(current == last)
    {
    deleteFromEnd();
    }else if(current != NULL)
    {    head->next = current->next;
        free(current);
        printf("deleted success.\n", position);
    }
    else
    {
        printf("Invalid position!\n");
    }
}

void search(int data) {
   int pos = 0;
   struct node *temp;

   if(head==NULL) {
      printf("Linked List not initialized");
      return;
   }

   current = head;
   while(current!=NULL) {
      pos++;
      if(current->data == data) {
         printf("%d found at position %d\n", data, pos);
          }
      if(current->next != NULL)
         current = current->next;
      else
        break;

   }
   printf("%d does not exist in the list\n", data);
}
