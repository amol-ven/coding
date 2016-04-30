#include <stdio.h>

int main()
{
	int v;
	int sign;
	
	//if v is not -ve then sign is 1 or its -1
	
	v = 10;
	
	//sign = (((v&0x80000000)==0)<<1)-1;
	printf("%x", v>>31);
	
}
