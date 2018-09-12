#include <stdlib.h>
#include <stdio.h>
#include <string.h>
/*************************************/
#define SIZE 30
/*************************************/ 
//Node template
struct Node
{
         char data[SIZE];
         struct Node *next;
};
/*************************************/
//prototypes
void instructions();
void enqueue(struct Node **headPtrRef, char info[SIZE]);
void dequeue(struct Node **head);
void printList(struct Node *head);
int *testFunction();
/*************************************/
void instructions()
{
        printf("Enter 0 to exit the program\n"
                "1 to insert a node to the linked list\n"
                "2 to delete a node from the list\n"
		"3 to print the list\n");
}
/*************************************/
void enqueue(struct Node **headPtrRef,char info[SIZE])
{
        //new node for adding to the list
        //struct Node *newNode = malloc(sizeof(newNode));
	struct Node *currentPtr = *headPtrRef;
	 	

 	//if current position does not exist
        //if(*headPtrRef == NULL)
	if(currentPtr == NULL)
        {
		struct Node *newNode = malloc(sizeof * newNode);
                *headPtrRef = newNode;
		strcpy(newNode->data,info); 
                newNode->next = NULL;
                return;
        }
        //if a list exists
	else
        {
                //traversing list to the end
                while(currentPtr->next != NULL)
                {
                        currentPtr = currentPtr->next;
                } 
	
		struct Node *tmpNode = malloc(sizeof * tmpNode);
		strcpy(tmpNode->data,info);
		tmpNode->next = NULL;
		currentPtr->next = tmpNode;
	}
        return;
}
/**************************************/
void dequeue(struct Node **head) 
{
	/* if no list */
	if(*head == NULL)
	{
		printf("No list to dequeue from\n");
		return;
	}
	/* if only 1 element */
	else if((*head)->next == NULL)
	{
		free(*head);
		head = NULL;
		
		return;
	}
	/* multiple nodes in list */
	else
	{
		struct Node *temp = *head;
		*head = (*head)->next;
		free(temp);
		temp = NULL;
		return;
	}
}
 /**************************************/
void printList(struct Node *head)
{
         while(head != NULL)
         {
                 //printing the contents
                 printf("%s",head->data);
                 printf("->");
                 //then moving to the next node
                 head = head->next;
         }

	 printf("NULL\n"); 
         return;
 }
 /*************************************/
 int main(void)
 {
         struct Node *head = NULL;
         char infoIn[SIZE];
 
         int choice = 0;
         printf("Enter an integer to continue:\n");
  
         instructions();
         scanf("%1d", &choice);
 
         while(choice != 0)
         {
                 switch(choice)
                 {
                         case 1:
                                printf("Enter a word to the list\n");
				scanf("%29s",infoIn);
                                enqueue(&head,infoIn);
                                printList(head);
                                instructions();
                                scanf("%d", &choice);
                                break;
                         case 2:
                  		dequeue(&head);
				printList(head);
				instructions();
				scanf("%1d", &choice);
                                break;
                         case 3:
                                instructions();
                                scanf("%d", &choice);
                                break;
                         case 4:
                                instructions();
                                scanf("%d", &choice);
                                break;
			 case 5:
				printList(head);
				instructions();
				scanf("%d", &choice);
				break;
                         default:
                                printf("Invalid choice, try again\n");
                                instructions();
                                scanf("%d", &choice);
                                break;
                 }
         }
         printf("End of run\n");
         return 0;
}
/****************************************/
