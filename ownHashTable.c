#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**********************************************/
//Hash table implementation of a student roster
/**********************************************/
struct Node
{
	int idNum;
	int hashedVal;
	char *name;
	struct Node *next;
};
/**********************************************/
struct List
{
	struct Node *head;
	struct Node *tail;
};
/**********************************************/
/**********************************************/
//global array and table
struct List hashTable[23];
/**********************************************/
//Function prototypes
void insert(int id, char *givenName);
int hashFunction(int identifier);
void search();
void delete();
void display();
void destroy();
/**********************************************/
int main()
{
	int choice;
	printf("Hash Table Program\n");

	insert(5, "john");
	insert(3, "aaron");
	insert(1, "nick");

	display();

	return 0;
}
/**********************************************/
void insert(int id, char *givenName)
{
	int hashVal = hashFunction(id);
	struct Node *newNode = malloc(sizeof(struct Node));
	struct Node *list = hashTable[hashVal].head;


	newNode-> idNum = id;
	newNode->hashedVal = hashVal;
	newNode->name = givenName;
	newNode->next = NULL;
	

	if(list == NULL)
	{
		
	} 	
}
/**********************************************/
int hashFunction(int identifier)
{
	int newHashVal = 0;
	newHashVal = identifier % 23;
	return newHashVal;
}
/**********************************************/
/**********************************************/
/**********************************************/
void display()
{
	for(int i = 0; i < 23; i++)
	{
		printf("\nBucket %d: ",(i+1));
		struct Node *temp = hashTable[i].head;
		while(temp != NULL)
		{	
			printf("%d\t",temp->idNum);
			printf("%s", temp->name);
			temp = temp->next;
		}
	}
}
/**********************************************/
/*
void destroy()
{
	struct Node *temp1;
	struct Node *temp2;
	for(int i = 0; i < 23; i++)
	{
		temp1 = hashTable[i];
		temp2 = hashTable[i];
		if(hashTable[i] != NULL)
		{
			while(temp1 != NULL)
			{
				temp2 = temp1;
				temp1 = temp1->next;	
				free(temp2);
			}
		}
	}
}
*/
