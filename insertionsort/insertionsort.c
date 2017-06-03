#include <stdio.h>

void isort(int *arr, int nr_elem)
{
	int key;
	int key_num;
	int pos;

	for(key=1; key<nr_elem; key++)
	{
		key_num = arr[key];
		for(pos=key-1; pos>=0; pos--)
		{
			//check if key_num needs to bet at pos+1
			if(key_num < arr[pos])
			{
				arr[pos+1] = arr[pos];
			}
			else
			{
				break;
			}
		}
		arr[pos+1] = key_num;
	}
}

int main()
{
	int a[] = {10, 4, 2, 8, 3, 9, 7, 5, 6};
	int nr_elem = (int)(sizeof(a)/sizeof(a[0]));
	int i;

	isort(a, nr_elem);

	for(i=0; i<nr_elem; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");

	return 0;
}
