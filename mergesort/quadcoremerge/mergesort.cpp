#include <iostream>
#include <stdlib.h>
#include <sys/time.h>
#include <omp.h>
#include <stdio.h>
#include <sys/resource.h>
using namespace std;

//#define SAMPLES 5000
#define SAMPLES 4000000

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
	struct rlimit rl;
	int ret = getrlimit(RLIMIT_STACK, &rl);
	
	
	const rlim_t kStackSize = 16L * 1024L * 1024L;   // min stack size = 64 Mb
	
	if(ret==0)
	{
		cout<<"Stack Size = "<<rl.rlim_cur / 1024 / 1024<<"M"<<endl;
		if (rl.rlim_cur < kStackSize)
        {
            rl.rlim_cur = kStackSize;
            ret = setrlimit(RLIMIT_STACK, &rl);
            if (ret != 0)
            {
                cout<<"Cannot set stack size. setrlimit returned "<<ret<<"."<<endl;
            }
        }
	}
	else
	{
		cout<<"cannot read stack size. getrlimit returned"<<ret<<"."<<endl;
	}
	
	ret = getrlimit(RLIMIT_STACK, &rl);
	if (ret != 0)
	{
		cout<<"Cannot read stack size. getrlimit returned "<<ret<<"."<<endl;
	}
	else
	{
		cout<<"Stack Size = "<<rl.rlim_cur / 1024 / 1024<<"M"<<endl;
	}
	
	
	/*
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
	*/
	
	//int samples[SAMPLES];
	
	srand(time(NULL));
	int *samples = (int *)malloc(SAMPLES*sizeof(int));
	if(samples)
	{
		cout<<"good\n";
	}
	else
	{
		cout<<"bad\n";
	}
	
	for(int i=0;i<SAMPLES;i++)
	{
		samples[i] = rand();
	}
	
	for(int i=SAMPLES/2; i<=SAMPLES/2 + 2; i++)
	{
		cout<<samples[i]<<endl;
	}
	
	cout<<"\nsorted\n";

struct timeval startt, endt;
gettimeofday(&startt, NULL);



	int procs = omp_get_num_procs();
	
	//cout<<"procs="<<procs<<endl;
	
	///   4 threads..
	#pragma omp parallel num_threads(procs)
	{
		int start, end;
		int threads = omp_get_num_threads();
		int i = omp_get_thread_num();
		
		start = (SAMPLES/threads)*(i);
		end   = ((SAMPLES/threads)*(i+1))-1;

		msort(samples, start, end);
	}
	
	procs /= 2;
	
	while(procs>=2)
	{
		///result is 4 sorted sub arrays
		///use 2 threads 
		#pragma omp parallel num_threads(procs)
		{
			int threads = omp_get_num_threads();
			int i = omp_get_thread_num();
			
			int start, end;
			
			start = (SAMPLES/threads)*(i);
			end   = ((SAMPLES/threads)*(i+1))-1;
			
			
			int length = end-start+1;
			int newarr[length];
			
			int leftend = start + (end-start)/2;
			int left = start, right = leftend+1;
			
			for(int newindex=0; newindex<length; newindex++)
			{
				if((samples[left]<samples[right] || right>end) && left<=leftend)
				{		
					newarr[newindex] = samples[left];
					left++;
				}
				else
				{
					newarr[newindex] = samples[right];
					right++;
				}
			}
			
			for(int index=0; index<length; index++)
			{
				samples[start+index] = newarr[index];
			}
		}
		
		procs /= 2;
		
	}

	///result is 2 sorted sub arrays
	///use 1 thread to merge them
	int threads = omp_get_num_threads();
	int i = omp_get_thread_num();
	
	int start, end;
	
	start = (SAMPLES/threads)*(i);
	end   = ((SAMPLES/threads)*(i+1))-1;
	
	
	int length = end-start+1;
	int newarr[length];
	
	int leftend = start + (end-start)/2;
	int left = start, right = leftend+1;
	
	for(int newindex=0; newindex<length; newindex++)
	{
		if((samples[left]<samples[right] || right>end) && left<=leftend)
		{		
			newarr[newindex] = samples[left];
			left++;
		}
		else
		{
			newarr[newindex] = samples[right];
			right++;
		}
	}
	
	for(int index=0; index<length; index++)
	{
		samples[start+index] = newarr[index];
	}


//	This is just serial execution.
//	msort(samples, 0, SAMPLES-1);
	
gettimeofday(&endt, NULL);
int millisec = (endt.tv_sec*1000 + endt.tv_usec/1000)-(startt.tv_sec*1000 + startt.tv_usec/1000);
cout<<"execution time = "<<millisec<<" ms\n";	
	for(int i=SAMPLES/2; i<=SAMPLES/2 + 2; i++)
	{
		cout<<samples[i]<<endl;
	}
	
	return 0;
}
