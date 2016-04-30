#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int reduce(char *str, int start, int end)
{
	int lastindex = strlen(str)-1;
	if(start<0 || end>lastindex)
	{
		return -1;
	}
	
	int i, j;
	i=start;
	j=end+1;
	
	while(j<=lastindex)
	{
		str[i++] = str[j++];
	}
	str[i] = '\0';
	
	return 0;
}


void recur(char *str, char *final, char **subs, int nsubs)
{
	if(strlen(str)<strlen(final))
	{
		strcpy(final, str);
	}
	int index=0;
	while(index<strlen(str))
	{
		int i;
		for(i=0;i<nsubs;i++)
		{
			if(strncmp(&str[index], subs[i], strlen(subs[i]))==0)
			{
				char back[strlen(str)];
				strcpy(back, str);
				reduce(str, index, strlen(subs[i])+index-1);
				recur(str, final, subs, nsubs);
				strcpy(str, back);			
			}
		}
		index++;
	}
}

int main()
{
	//char str[] = "abababcdefeghi";
	//char str[] = "abav";
	//char *subs[] = {"a", "b", "ab", "bbb"};
	
	char str[] = "ababbbabbaabbbba";
	char *subs[] = {"ab" ,"abb"};
	
	int nsubs = sizeof(subs)/sizeof(subs[0]);
	//int len = strlen(str);
	
	char final[strlen(str)];
	strcpy(final, str);
	//reduce(str, 0 ,0);
	recur(str, final, subs, nsubs);
	//char **s = subs;
	printf("Reduced: %s\n", final);
	
}
