#include <stdio.h>
#include <stdlib.h>

char str[] = "abcd";
int len = 4;

void swap(char *c1, char *c2)
{
	char temp = *c1;
	*c1 = *c2;
	*c2 = temp;
}

void perm(char *s, int substart, int subend)
{
	if(substart==subend)
	{
		printf("%s\n", s);
	}
	else
	{
		int i;
		for(i=substart;i<=subend;i++)
		{
			swap(&s[substart], &s[i]);
			perm(s, substart+1, subend);
			swap(&s[substart], &s[i]);    //backtracking
		}
	}
}

int main(void)
{
	perm(str, 0, len-1);
}


/*
amol@amolsystem ~/Desktop/coding/permutations $ ./a.out 
abcd
abdc
acbd
acdb
adcb
adbc
bacd
badc
bcad
bcda
bdca
bdac
cbad
cbda
cabd
cadb
cdab
cdba
dbca
dbac
dcba
dcab
dacb
dabc
amol@amolsystem ~/Desktop/coding/permutations $ 
*/
