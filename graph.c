#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
/*****************************************************************************/
bool adjMatrix[5][5];
/*****************************************************************************/
void read();
/*****************************************************************************/
int main(int argc, char **argv)
{
	read();
	

	return 0;
}
/*****************************************************************************/
void read()
{
	FILE *f = fopen("pairs.txt","r");
	char buff[255];
	char *resStr;

	
	if(f == NULL)
	{
		printf("Error reading file");
		exit(1);
	}
	else
	{
		while(fgets(buff, 255, f))
		{
			char *line = buff;
			resStr = strtok(line, "( , )");
			printf("%s\n", resStr);
		}
	}
	fclose(f);
}
/*****************************************************************************/
