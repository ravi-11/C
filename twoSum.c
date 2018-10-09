/*C program that takes an array and returns the indices of the two numbers
  such that they add up to a specific target */


#include <stdio.h>
#include <stdlib.h>

#define SIZE 10
/**************************************************************/
//prototypes
int *twoSum(int *nums, int numsSize, int target);
/**************************************************************/
int main(void)
{
	/* Random array to test the twoSum function */
	int testArray1[SIZE] = { 
				 8, 4, 3, 54, 12, 
				 54, 12, 2, 34, 66
			       };

	/* Our target value */
	int targetKey = 62; 

	/* pointer variable to hold return value of twoSum function */
	int *twoSumPtr = twoSum(testArray1, SIZE, 62);


	/* deallocating the memory in the heap */
	free(twoSumPtr);
	twoSumPtr = NULL;

	return 0;
}
/**************************************************************/
int *twoSum(int *nums, int numsSize, int target)
{
	/* array to hold the indices */
	int *indicesReturned = malloc(3 * sizeof(int *)); 
	int length = sizeof(indicesReturned)/ sizeof(int);
	
	/* if flag is 1 we have succeeded */
	int flag = 0;

	/* loop variables */
	int i = 0, j = 0;

	/* Nested for loop to add each value at each position to our current position */
	for(i = 0; i < SIZE; i++)
	{
		for(j = 1; j < SIZE; j++)
		{
			if(nums[i] + nums[j] == target)
			{
				indicesReturned[i] = nums[i];
				indicesReturned[j] = nums[j];
		
				printf("The two indices are:\n");
				printf("Index 1: %d\n",i);
				printf("Index 2: %d\n",j);

				flag = 1;		
				break;
			}
		}
		
		/* break out of the total loop if we have found are target indices */
		if(flag)
		{
			break;
		}
	}

	printf("Numbers at the indices are: ");

	printf("%d, ", indicesReturned[i]);
	printf("%d", indicesReturned[j]);
	printf("\n");

	return indicesReturned;
}
/**************************************************************/
