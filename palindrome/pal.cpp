#include <iostream>
#include <string.h>

using namespace std;


int palnopal(char *str, int start, int end)
{
	int pal=1;
	for(;start<=end; start++, end--)
	{
		if(str[start]!=str[end])
		{
			pal=0;
			break;
		}
	}
	if(pal==1)
	{
		return 0;
	}
	else
	{
		return -1;
	}
}

int main()
{
	char str[] = "madam";
	int len = strlen(str);
	
	int palcount=0;
	
	for(int start=0; start<=len-1; start++)
	{
		for(int end=len-1; end>=start; end--)
		{
			if(palnopal(str, start, end) == 0)
			{
				palcount++;
			}
		}
	}
	
	cout<<palcount;
	return 0;
}
