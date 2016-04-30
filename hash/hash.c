#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct data
{
	char name[10];
	int number;
	struct data * link;
};

int hash(char *name)
{
	int sum=0;
	
	for(int index=0; name[index]!=0; index++)
	{
		sum+=name[index];
	}
	
	return sum%10;
}


void add(struct data ** hashtable_addr, char *name, int number)
{
	int loc = hash(name);
	
	//go to tail of the loc'th chain.
	
	struct data * p1 = NULL;
	struct data * p2 = hashtable_addr[loc];
	int chain_count = 0;
	while(p2)
	{
		p1 = p2;
		p2 = p2->link;
		chain_count++;
	}
	if(!p1)
	{
		//first time
		hashtable_addr[loc] = (struct data *)malloc(sizeof(struct data));
		hashtable_addr[loc]->number = number;
		strncpy(hashtable_addr[loc]->name, name, 10);
		hashtable_addr[loc]->name[9] = '\0';
	}
	else
	{
		
	
	
		p2 = (struct data *)malloc(sizeof(struct data));
		p2->number = number;
		strncpy(p2->name, name, 10);
		p2->name[9] = '\0';

	printf("linked\n");
		p1->link = p2;


	}
	
	printf("added at loc = %d, chain_count = %d\n", loc, chain_count);
/*
	if(p1)
	{
		printf("linked\n");
		p1->link = p2;
	}
	*/
}


int retreive(struct data ** hashtable_addr, char *name)
{
	int loc = hash(name);
	int ret = -1;
	struct data * p = hashtable_addr[loc];
	
	while(p)
	{
		if( memcmp(p->name, name, strlen(name)+1)==0)
		{
			ret = p->number;
			break;
		}
		else
		{
			p = p->link;
		}
	}
	return ret;
}
	
	


int main()
{
	//Amoll and Amolla hash same
	
	int loc = hash("Amol");
	
	printf("loc = %d\n", loc);
	
	
	//struct data * hashtable [10] = { 0 };
	
	struct data ** hashtable = (struct data **)calloc(10, sizeof(struct data *));
	
	add(hashtable, "Amoll", 99);
	add(hashtable, "Amolljs", 999);
	
	
	int r = retreive(hashtable, "Amolljs");
	printf("r = %d\n", r);
	
	
	
	
	
	
	
	
	return 0;
}
