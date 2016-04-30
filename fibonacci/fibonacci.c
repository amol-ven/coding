#include <stdio.h>

/*
int main()
{
	int a=0, b=1;
	int count;
	printf("%d\n", a);
	for(count=1;count<=10;count++)
	{
		int b_old = b;
		b = b+a;
		a = b_old;
		printf("%d\n", b);
	}
}
*/


void fibo(int a, int b, int count)
{
	if(count>0)
	{
		printf("%d\n", a);
		fibo(b, b+a, count-1);
	}
}


int main()
{
	fibo(0, 1, 10);
}
