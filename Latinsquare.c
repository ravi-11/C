/* program that reads in a file and checks whether it is a Latin square */
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
/************************************************/
#define BUFFER 30
#define TOTALSTRS 30
/************************************************/
char **openAndScan();
void freeMemory(char **strsToFree);
void convertStrToAscii(char **givenStrArray);
bool isLatinSquare();
/************************************************/
char **openAndScan()
{
	/* variables for opening file, storing input
	and creating a pointer reference to array of strings */

	FILE *fp = NULL;
	int i = 0;
	fp = fopen("Latin.txt", "r");
	
	/* space for the number of strings */
	char **ptrsToStrings = malloc(TOTALSTRS * sizeof(char *));

	/* space for each individual string */
	for(int j = 0; j < TOTALSTRS; j++)
	{
		ptrsToStrings[j] = malloc((BUFFER+1) * sizeof(char));	
	}

	if(fp == NULL)
	{
		printf("Error with reading file\n");
		exit(EXIT_FAILURE);
	}

	else
	{
		while(fgets(ptrsToStrings[i], TOTALSTRS, fp))
		{
			ptrsToStrings[i][strlen(ptrsToStrings[i]) - 1] = '\0';
			i++;
		}

		printf("Now entering for loop of ptrsToStrings\n");
		for(int k = 0; k < TOTALSTRS; k++)
		{
			printf("%s\n",ptrsToStrings[k]);
		}
	}

	return ptrsToStrings;
}
/************************************************/
void freeMemory(char **strsToFree)
{
	int i = 0;

	/* loop through array freeing each string */
	for(int i = 0; i < TOTALSTRS; i++)
	{
		free(strsToFree[i]);
		strsToFree[i] = NULL;
	}

	free(strsToFree);
	strsToFree = NULL;
	
	return;
}
/************************************************/
void convertStrToAscii(char **givenStrArray)
{
	/* First need to distinguish numbers from characters */

	/* iterate through the string array first */
	for(int i = 0; i < TOTALSTRS; i++)
	{
		/* now iterating through each element in each string */
		for(int j = 0; j < BUFFER; j++)
		{
				/* condition check whether element ascii code is a number */
			if((int)(givenStrArray[i][j]) >= 48 && (int)(givenStrArray[i][j] <= 57))
			{
				//printf("element decimal num is %d, and the int is %c\n",givenStrArray[i][j], givenStrArray[i][j]);
			}
			else if((int)(givenStrArray[i][j]) >= 65 && (int)(givenStrArray[i][j] <= 90))
			{
				//printf("element decimal num is %d, and the letter is %c\n",givenStrArray[i][j],givenStrArray[i][j]);
			}

		}
	}
	return;
}
/************************************************/
int main(void)
{
	printf("Program that takes input to determine" 
		" if data contains latin squares\n");

	char **returnArray = openAndScan();
	freeMemory(returnArray);

	return 0;
}
