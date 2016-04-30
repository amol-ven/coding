#include <stdio.h>
#include <stdlib.h>

#define REF(mat, r, c, COLS) (*(mat+(r*COLS)+c))

typedef struct node
{
	int data;
	struct node *link;
}node_t;

void disp(int *mat, int rows, int cols)
{
	int r, c;
	for(r=0; r<rows; r++)
	{
		for(c=0; c<cols; c++)
		{
			printf("%d ", REF(mat, r, c, cols));
		}
		printf("\n");
	}
}

void transform(int *mat, int rows, int cols)
{
	node_t *collist, *prev;
	int r, c;
	
	for(c=0;c<cols;c++)
	{
		if(c==0)
		{
			collist = (node_t *)malloc(sizeof(node_t));
			collist->data = c;
			prev = collist;
		}
		else
		{
			prev->link = (node_t *)malloc(sizeof(node_t));
			prev->link->data = c;
			prev = prev->link;
		}
	}
	prev->link=NULL;
	
	printf("\n\n");
	node_t *colcurr, *colprev;
	
	for(r=0;r<rows;r++)
	{
		for(colcurr=collist, colprev=NULL; colcurr; colprev=colcurr, colcurr=colcurr->link)
		{
			c = colcurr->data;
			
			printf("[r c] = [%d %d]\n", r, c);
					
			if(REF(mat, r, c, cols) == 0)
			{
				int i;
				for(i=0; i<rows; i++)
				{
					REF(mat, i, c, cols) = 0;
				}
				for(i=0; i<cols; i++)
				{
					REF(mat, r, i, cols) = 0;
				}
				
				if(colprev==NULL)
				{
					collist = colcurr->link;
					//free(colcurr);
				}
				else
				{
					colprev->link = colcurr->link;
					//free(colcurr);
				}
				break;
			}
		}
	}
}

int main()
{	
	int rows = 3;
	int cols = 5;
	int matx[rows][cols];
	
	int *mat = (int *)matx;
	
	int r, c;
	for(r=0; r<rows; r++)
	{
		for(c=0; c<cols; c++)
		{
			REF(mat, r, c, cols) = 1;
		}
	}
	REF(mat, 0, 0, cols) = 0;
	REF(mat, 2, 1, cols) = 0;
	
	disp(mat, 3, 5);
	
	transform(mat, 3, 5);
	printf("\n");
	disp(mat, 3, 5);
}
