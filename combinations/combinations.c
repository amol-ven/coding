#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void recur(char *set, char* result, int result_index, int result_len, int set_len)
{
	if(result_index == result_len)
	{
		printf("%s\n", result);
	}
	else
	{
		int j = 0;
		for(j=0; j<set_len; j++)
		{
			result[result_index] = set[j];
			recur(set, result, result_index+1, result_len, set_len);
		}
	}
}

void recur_norepeat(char *set, char* result, int result_index, int *visited, int result_len, int set_len)
{
	if(result_index == result_len)
	{
		printf("%s\n", result);
	}
	else
	{
		int j;
		for(j=0; j<set_len; j++)
		{
			if(visited[j]==0)
			{
				visited[j]=1;
				recur_norepeat(set, result, result_index+1, visited, result_len, set_len);
				visited[j]=0;   //backtrack
			}
		}
	}
}
	
	
	
int main()
{
	char set[] = "abcde";
	int setlen = strlen(set);
	
	int visited[setlen];
	int i;
	for(i=0; i<setlen; i++)
	{
		visited[i] = 0;
	}
	
	char result[4];
	int resultnulllen = sizeof(result)/sizeof(result[0]);
	result[resultnulllen-1] = '\0';
	
	//recur(set, result, 0, resultnulllen-1, setlen); 
	recur_norepeat(set, result, 0, visited, resultnulllen-1, setlen);
	return 0;
}
