#include <stdio.h>
#include <stdlib.h>
#define ROWS 100

int main()
{
	FILE * data = fopen("triangle.txt", "r");
	if(!data)
	{
		printf("no open\n");
	}
	
	int x;
	char c;
	
	//build the data set
	int rownum, intinrow;
	int **nums = (int **)malloc(sizeof(int *)*ROWS);
	if(!nums)
	{
		printf("no headers\n");
		return -1;
	}
	for(rownum=0;rownum<ROWS;rownum++)
	{
		nums[rownum] = (int *)malloc(sizeof(int)*(rownum+1));
		if(!nums[rownum])
		{
			printf("no meory for row %d\n", rownum);
			return -2;
		}
	}
	
	for(rownum=0; rownum<ROWS; rownum++)
	{
		for(intinrow=0; intinrow<rownum+1; intinrow++)
		{
			//nums[rownum][intinrow] = 
			fscanf(data, "%d", &nums[rownum][intinrow]);
		}
	}
	
	
	int choosingrow = ROWS-1-1;
	int choicearray_length = choosingrow+1+1;
	
	int *choicearray = (int *)malloc(sizeof(int)*choicearray_length);
	for(intinrow=0; intinrow<choicearray_length;intinrow++)
	{
		choicearray[intinrow] = nums[choosingrow+1][intinrow];
	}
	
	printf("%d ", choicearray_length);
	for(intinrow=0; intinrow<choicearray_length;intinrow++)
	{
		printf("%d ", choicearray[intinrow]);
	}
	
	int
	
	
	
	
	
	
	//printf("%d\n", nums[ROWS-1][ROWS-1]);
}
