
#include <stdlib.h>
#include <stdio.h>

typedef struct element
{
	struct element *next;
	int data;
}node_t;



int add(int data, node_t **head)
{
	node_t *newnode = (node_t *)malloc(sizeof(node_t));
	if(!newnode)
	{
		printf("cannot allocate memory for new node\n");
		return -1;
	}
	newnode->data = data;
	newnode->next = NULL;
	
	node_t *last=*head, *curr;
	if(last)
	{
		curr = last->next;
		while(curr)
		{
			last = curr;
			curr = curr->next;
		}
	
		last->next = newnode;
	}
	else
	{
		//empty list.
		*head = newnode;
		
	}
	return 0;
}


int displist(node_t **addrofhead)
{
	node_t *ptr = *addrofhead;
	
	while((ptr)!=NULL)
	{
		printf("%d ", ptr->data);
		ptr = ptr->next;
	}
	printf("\n");
}


int hash(int key)
{
	int hashvalue = key%5;
	return hashvalue;
}

int addtohashtable(int data, node_t **startoftbl)
{
	int pos = hash(data);
	add(data, &startoftbl[pos]);
}

int main()
{
	/*node_t *head = NULL;
	
	add(1, &head);
	add(2, &head);
	add(3, &head);
	
	displist(&head);
	*/
	
	node_t *hashtbl[5];
	int i;
	for(i=0;i<=4;i++)
	{
		/*
		hashtbl[i].data = -1;
		hashtbl[i].next = NULL;
		*/
		hashtbl[i]=NULL;
	}
	
	
	
	
	addtohashtable(8, hashtbl);
	
	addtohashtable(3, hashtbl);
	
	
	displist(&hashtbl[3]);
	
	
	
}
