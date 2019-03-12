#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
/*****************************************************************************/
bool adjMatrix[5][5];
/*****************************************************************************/
void read();
void printMatrix();
/*****************************************************************************/
int main(int argc, char **argv)
{
	read();
	int i = 0;

	printMatrix();
	return 0;
}
/*****************************************************************************/
void read()
{
	FILE *f = fopen("pairs.txt","r");
	char buff[255];
	int xFlag, yFlag;
	long xLoc, yLoc;
	char *ptr;

	if(f == NULL)
	{
		printf("Error reading file");
		exit(1);
	}
	else
	{
		while(!feof(f))
		{
			/* grab the current line from text file and put into buff */
			fgets(buff,6,f);
			//printf("%s",buff); //displays what is in buffer
			
			/* now scan that line that is in buff */
			for(int i = 0; i < 6; i++)
			{
				/* if we have not found our first number go into here */
				if(xFlag != 1)
				{
					/* if the current character is a number */
					if(buff[i] >= '0' && buff[i] <= '9')
					{
						printf("First number of string is: %c\t", buff[i]);
						long num = strtol(buff,&ptr,10);

						/* we have found our x Location of adjMatrix */
						xLoc = num;
						/* we have found our first number, now on to second */
						xFlag = 1;
					}

				}
				/* if we already have our first number */
				else
				{
					/* is the current character a number? */
					if(buff[i] >= 0 && buff[i] <= 9)
					{
						//printf("Second number of string is: %d\t", buff[i]);
						/* second number is our y Location of adjMatrix */
						long num = strtol(buff,&ptr,10);
						yLoc = num;
						/* we now have our second number */
						yFlag = 1;
					}

				}
				/* if we have both x and y location numbers */
				if(xFlag == 1 && yFlag == 1)
				{
					//printf("x:%d, y:%d",buff[xLoc], buff[yLoc]);
					//printf("\n");
					/* set the relationship between both numbers to true */
					adjMatrix[xLoc][yLoc] = true;
				}
			}
			printf("\n");

			/* restart for the next string that is read in */
			xFlag = 0;
			yFlag = 0;
		}
	}
	fclose(f);

}
/*****************************************************************************/
void printMatrix()
{
	for(int i = 0; i < 5; i++)
	{
		for(int j = 0; j < 5; j++)
		{
			printf("%d", adjMatrix[i][j]);
		
		}
		printf("\n");
	}
}
