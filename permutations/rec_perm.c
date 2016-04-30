#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long long int lexid(char *s1, char *s2, int len)
{
	long long int dist=0;
	long long int weight=1;
	int i;
	for(i=len-1; i>=0; i--)
	{
		dist += ((s2[i]-s1[i])*weight);
		weight *= 26;
	}
	return dist;
}

void recur(char *sorted, char *result, char *target, int choosing_index, int len, int *mark)
{
	static int state = 0;
	if(choosing_index == len)
	{
		if(state == 0)
		{
			state=1;
		}
		else
		{
			printf("This may be it %s\n", result);
			state = 2;
		}
		//printf("%s   %lld\n", result, lexid(src, result, len));
		
	}
	else
	{
		int mark_index;
		for(mark_index=0; mark_index<len; mark_index++)
		{
			if(mark[mark_index]==0)
			{
				mark[mark_index]=1;
				result[choosing_index] = sorted[mark_index];
				if( (state==0 && result[choosing_index]==target[choosing_index]) || (state==1) )
				{
					recur(sorted, result, target, choosing_index+1, len, mark);
				}
				mark[mark_index]=0;
			}
		}
	}
}

int compare(const void *e1, const void *e2)
{
	char c1 = *((int *)e1);
	char c2 = *((int *)e2);
	return c1>c2?1:-1;
}

int main()
{
	
	char str[] = "bb";
	int len = strlen(str);
	int mark[len];
	int i;
	for(i=0;i<len;i++)
	{
		mark[i] = 0;
	}
	
	char sorted[len+1];
	strncpy(sorted, str, len+1);
	qsort(sorted, len, sizeof(char), compare);
	
	char result[len+1]; 
	result[len] = '\0';

	recur(sorted, result, str, 0, len, mark);
	
}


