#include <stdio.h>
#include <stdlib.h>

int ** arr2d(int rows, int columns)
{
	int **headers = (int **)malloc(rows*sizeof(int *));
	if(!headers)
	{
		printf("No mem\n");
		return NULL;
	}
	int i;
	for(i=0;i<columns;i++)
	{
		headers[i] = (int *)malloc(columns*sizeof(int));	
		if(!headers[i])
		{
			printf("No mem\n");
			return NULL;
		}
	}
	return headers;
}

void disp2D(int **arr, int rows, int columns)
{
	int i, j;
	for(i=0;i<rows;i++)
	{
		for(j=0;j<columns;j++)
		{
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
}

int main()
{
	int **mat = arr2d(2, 2);
	if(!mat)
	{
		printf("bad\n");
	}
	else
	{
		printf("good\n");
	}
	
	
	
	fflush(stdout);
	mat[0][0] = 0;
	mat[0][1] = 1;
	mat[1][0] = 2;
	mat[1][1] = 3;
	
	disp2D(mat, 2, 2);
	
	return 0;
}
