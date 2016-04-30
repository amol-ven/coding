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
		int src_index=0;
		while(1)
		{
			if(0 != src[src_index])
			{
				result[pos] = src[src_index];
				src[src_index] = 0;
				print(src, result, pos+1, len);
				src[src_index] = result[pos];
			}
			
			src_index++;
			if(src_index == len)
			{
				break;
			}
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
