#include <stdio.h>
#include <string.h>


int main()
{
	char str[] = "aadwcbbbbctg";
	int n = strlen(str);
	
	char c=0;
	int i;
	for(i=0;i<n;i++)
	{
		c ^= str[i];
	}
	
	if(c==0)
	{
		printf("Yes\n");
	}
	else
	{
		if(n%2 == 1)
		{
			printf("Yes ... middle is %c\n", c);
		}
		else
		{
			printf("No\n");
		}

	}
		
	
	
	
}
