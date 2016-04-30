#include <iostream>

using namespace std;

void msort(int *arr, int start, int end)
{
	if(end > start)
	{
		int leftend = start + (end-start)/2;
		msort(arr, start, leftend);
		msort(arr, leftend+1, end);
		
		int length = end-start+1;
		int newarr[length];
				
		int left = start, right = leftend+1;
		
		for(int newindex=0; newindex<length; newindex++)
		{
			if((arr[left]<arr[right] || right>end) && left<=leftend)
			{		
				newarr[newindex] = arr[left];
				left++;
			}
			else
			{
				newarr[newindex] = arr[right];
				right++;
			}
		}
		
		for(int index=0; index<length; index++)
		{
			arr[start+index] = newarr[index];
		}
	}
	else
	{ 
		//else do nothing
	}
}


int main()
{
	int arr[10] = {1, 8, 3, 6, 2, 0, 7, 4, 5, 9};
	int start = 0;
	int end = 9;
	int len = end-start+1;
	
	
	msort(arr, start, end);
	
	for(int i=0; i<len; i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	return 0;
}
