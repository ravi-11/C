#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
/*****************************************************************************/
bool adjMatrix[5][5];
/*****************************************************************************/
char *read();
/*****************************************************************************/
int main(int argc, char **argv)
{
	char *pairs = read();
	

	for(int i = 0; i < 256; i++)
	{
		printf("%c",pairs[i]);
	}
	free(pairs);	
	return 0;
}
/*****************************************************************************/
char *read()
{
	FILE *f = fopen("pairs.txt","r");
	char buff[255];
	char *retStr = malloc(256 * sizeof(char));
	
	if(f == NULL)
	{
		printf("Error reading file");
		exit(1);
	}
	else
	{
		while(fgets(buff, 255, f))
		{
			strncpy(retStr,buff,255);	
		}
	}
	fclose(f);
	return retStr;
}
/*****************************************************************************/
