#include <stdio.h>
#include <string.h>


int patternmatch(char *str1, int start1, int end1,
				 char *str2, int start2, int end2)
{
	int index1, index2;
	int match = 1;
	for(index1=start1, index2=start2 ;index1<=end1, index2<=end2 ; index1++, index2++)
	{
		if(str1[index1]!=str2[index2])
		{
			match=0;
			break;
		}
	}
	return match;
}

int seek(char *str, int curr, char target)
{
	int i;
	for(i=curr+1; ;i++)
	{
		if(str[i]==target)
		{
			return i;
		}
		if(str[i]=='\0')
		{
			return -1;
		}
	}
}
int main()
{
	char in[10], pat[10];
	
	scanf("%s", in);
	fflush(stdin);
	scanf("%s", pat);
	
	
	
	int inlen = strlen(in);
	int patlen = strlen(pat);

	int in_index=0, pat_index=0, match=1;
	
	
	while(1)
	{
		if(pat[pat_index]=='*')
		{
			int nextstar = seek()
		}
		
		else
		{
			if(pat[pat_index]==in[in_index] || pat[pat_index]=='?')
			{
				in_index++;
				pat_index++;
				if(in_index=='\0')
				{
					break;
				}
			}
			else
			{
				match=0;
				break;
			}
		
		
	}
	
	
