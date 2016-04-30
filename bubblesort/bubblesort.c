#include <stdio.h>

int arr[] = {122, 24, 23, 21, 20, 14, 13, 12, 11, 10};

void swap(int *i1, int *i2)
{
	int temp = *i1;
	*i1 = *i2;
	*i2 = temp;
}

int main()
{
	int length = sizeof(arr)/sizeof(arr[0]);
	
	int i=0, j=0;
	for(i=length-2;i>=0;i--)
	{
		for(j=0;j<=i;j++)
		{
			if(arr[j]>arr[j+1])
			{
				swap(&arr[j], &arr[j+1]);
			}
		}
	}
	
	for(i=0;i<=length-1;i++)
	{
		printf("%d\n", arr[i]);
	}
	
	
}
