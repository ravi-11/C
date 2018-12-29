#include <stdio.h>
#include <stdlib.h>
/*******************************************************************************/
int comparator(const void *a, const void *b);
void print(int *array, int len);
int findTarget();
int binarySearch(int *array, int len, int target);
int helper(int *array, int left, int right, int mid, int target);
/******************************************************************************/
int main(int argc, char **argv)
{
	/* array that will be used to test recursive binary search */
	int arr[15] = {0};

	for(int i = 0; i < 15; i++)
	{
		arr[i] = rand() % 75;
	}

	qsort(arr, 15, sizeof(int), comparator);
	print(arr, 15);
	
	int tgt = findTarget();

	int binSearch = binarySearch(arr, 15, tgt);

	printf("Target found is %d\n", binSearch);

	return 0;
}
/******************************************************************************/
int comparator(const void *a, const void *b)
{
  /* return value for the qsort function */
	return (* (int *)a - *(int *)b);
}
/******************************************************************************/
void print(int *array, int len)
{
	for(int i = 0; i < len; i++)
	{
		printf("%d\n", array[i]);
	}
	return;
}
/******************************************************************************/
int findTarget()
{
	int tgt;
	printf("Enter number to retrieve and remove from the list\n");
	scanf("%2d", &tgt);

	return tgt;
}
/******************************************************************************/
int binarySearch(int *array, int len, int target)
{
	/* find middle of array and set boundaries */
	int mid = len / 2;
	int left = 0, right = len-1;	

	int search = helper(array, left, right, mid, target);

	return search;
}
/*****************************************************************************/
int helper(int *array, int left, int right, int mid, int target)
{
	/* return mid if it is the target */
	if(array[mid] == target)
	{
		return array[mid];
	}
	else if(target > array[mid])
	{
		printf("Target is greater than mid\n");
		left = mid+1;
		mid = (left+right) / 2;
		helper(array, left, right, mid, target);
	}
	else if(target < array[mid])
	{
		printf("Target is less than mid\n");
		right = mid-1;
		mid = (left+right) / 2;
		helper(array, left, right, mid, target);
	}
	else
	{
		printf("Target is not in the list\n");
		return 1;
	}
}
/******************************************************************************/
