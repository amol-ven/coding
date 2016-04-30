#include<iostream>
#include<stdlib.h>

using namespace std;

class list_element
{
	private:
	int data;
	list_element *link;
	public:
	list_element();
};

void merge(int a[], int start, int end)
{
	cout<<"M:"<<start<<' '<<end<<endl;
	if(start<end)
	{
		//recurssion
		merge(a, start, (start+end)/2);
		merge(a, (start+end)/2 +1, end);
	}
	else
	{
		//pull out of recurssion
	}
	
	//now sort
	//start and end tell us how deep we are in recurssion.
	//if start == end we are at deepest level
	if(start == end)
	{
		//deepest level of recurssion.
		//do nothing.
	}
	else
	{
		int left_length = (start+end)/2 - start + 1;
		int right_length = end - ((start+end)/2+1) + 1;
		int left[left_length], right[right_length];
		
		cout<<"start:"<<start<<"  end:"<<end<<"  left_length:"<<left_length<<"  right_length:"<<right_length<<endl;
		cout<<"--------\nL:";
		int i;
		for(i=0;i<left_length;i++)
		{
			left[i] = a[start+i];
			cout<<left[i]<<' ';
		}
		cout<<"  R:";
		for(i=0;i<right_length;i++)
		{
			right[i] = a[(start+end)/2+1+i];
			cout<<right[i]<<' ';
		}
		cout<<endl<<"---------"<<endl;
		
		
		int l=0, r=0, m=0;
		int merged_length = left_length+right_length;
		int merged[merged_length];
		int left_done=0, right_done=0;
		for(m=0;m<merged_length;m++)
		{
			if(left[l] < right[r])
			{
				merged[m] = left[l++];
				cout<<"add left one to merged:"<<left[l-1]<<endl;
				if(l==left_length)
				{
					cout<<"leftdone";
					left_done=1;
					break;
				}
			}
			else
			{
				merged[m] = right[r++];
				cout<<"add right one to merged:"<<right[r-1]<<endl;
				if(r==right_length)
				{
					cout<<"rightdone";
					right_done=1;
					break;
				}
			}
		}
		if(left_done==1)
		{
			for(;m<merged_length;m++,r++)
			{
				cout<<"leftdone..adding pending rights:"<<right[r];
				merged[m] = right[r];
			}
		}
		if(right_done==1)
		{
			for(;m<merged_length;m++,l++)
			{
				merged[m] = left[l];
			}
		}
		
		for(i=0;i<merged_length;i++)
		{
			a[start+i] = merged[i];
		}
	}
		
}

int main()
{
	int A[] = {1, 5, 3, 7, 2, 4};
	
	int length = sizeof(A)/sizeof(A[0]);
	
	merge(A, 0, length-1);
	
	int i;
	for(i=0;i<length;i++)
	{
		cout<<A[i]<<' ';
	}
}
