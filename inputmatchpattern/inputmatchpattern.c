#include <stdio.h>
#include <string.h>


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
		if(pat[pat_index]=='?')
		{
			printf("a0");
			in_index++;
			pat_index++;
			//if(in_index >= inlen)
		}
		else if(pat[pat_index]=='*')
		{
			int in_scan = inlen-1;
			char search = pat[pat_index+1];
			int found=0;
			for(in_scan = inlen-1; in_scan>=in_index; in_scan--)
			{
				if(in[in_scan]==search)
				{
					found=1;
					break;
				}
			}
			if(found==1)
			{
				in_index = in_scan;
				pat_index++;
			}
			else
			{
				match=1;
				break;
			}
					
			/*
			if(pat[pat_index+1]==in[in_index])
			{
				if(in[in_index]=='\0')
				{
					printf("a2");
					break;//match
				}
				pat_index+=2;
				in_index++;
				printf("a1");
			}
			 
			
			//else if(in[in_index]=='\0')
			//{
				//printf("a2");
				//break;//match
			//}
			
			else
			{
				printf("a3");
				in_index++;
			}
			*/ 
		}
		else
		{
			if(pat[pat_index]!=in[in_index])
			{
				printf("a4");
				match=0;
				break;
			}
			else
			{
				if(pat[pat_index] == '\0')
				{
					printf("a5");
					break;
				}
				else
				{
					printf("a6");
					pat_index++;
					in_index++;
				}
			}
		}
	}
	
	if(match==0)
	{
		printf("\n\nnot a match\n");
	}
	else
	{
		printf("\n\nMatch\n");
	}
	
	return 0;
}
