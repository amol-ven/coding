#include <stdio.h>

void print(char *src, char *result, int pos, int len)
{
	//last index = len
	if(pos == len)
	{
		//end recur.
		//print result
		result[len] = '\0';
		printf("%s\n", result);
	}
	else
	{
		int i=0;
		for(i=0;i<len;i++)
		{
			result[pos] = src[i];
			print(src, result, pos+1, len);
		}
	}
}
		
		
		

int main()
{
	char test[] = "test";
	char result[sizeof(test)/sizeof(test[0])];
	
	print(test, result, 0, 4);
	
	return 0;
}
