#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
/*****************************************************************************/
bool adjMatrix[5][5];
/*****************************************************************************/
void read();
uint8_t getNum(char a, uint8_t ret);
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
	char symb;
	uint8_t x = 255, y = 255, ret = 255;
	uint8_t xLoc, yLoc;
	bool firstIteration = false, secondIteration = false;

	if(f == NULL)
	{
		printf("Error reading file");
		exit(1);
	}
	else
	{
		while((symb=getc(f)) != EOF)
		{
			printf("x is: %d\n",x);
			x = getNum(symb, ret);
			if(x >= 0 && x <= 9)
			{
				if(firstIteration == false)
				{
					//printf("In firstIteration xLoc: %d\t", x);
					xLoc = x;
					firstIteration = true;
				}
				else if(secondIteration == false)
				{
					//printf("In secondIteration yLoc: %d\t", x);
					yLoc = x;
					secondIteration = true;
					printf("\n");
					printf("adjMatrix[%d][%d]\n",xLoc, yLoc);
					adjMatrix[xLoc][yLoc] = true;
					firstIteration = false;
					secondIteration = false;
				}
			}
		}
	}
	fclose(f);

}
/*****************************************************************************/
uint8_t getNum(char a, uint8_t ret)
{
	unsigned char b;
	b = (unsigned char)a;
	if(b >= '0' && b <= '9')
	{
		ret = b - '0';
		return ret;
	}
	return -1;
}
/*****************************************************************************/
void printMatrix()
{
	printf("\n");
	for(int i = 0; i < 5; i++)
	{
		for(int j = 0; j < 5; j++)
		{
			printf("%d", adjMatrix[i][j]);
		
		}
		printf("\n");
	}
}
