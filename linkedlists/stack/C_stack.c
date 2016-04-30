#include<stdio.h>
#include<stdlib.h>

typedef struct element
{
	struct element *link;
	int data;
}node_t;


int displist(node_t **addrofhead)
{
	node_t *ptr = *addrofhead;
	
	while((ptr)!=NULL)
	{
		printf("%d ", ptr->data);
		ptr = ptr->link;
	}
	printf("\n");
}


int push(int data, node_t **headptr)
{
	if(!(*headptr))
	{
		//no node exists.
		//pushing first node.
		node_t *ptr = (node_t *)malloc(sizeof(node_t));
		if(!ptr)
		{
			printf("cannot allocate memory\n");
			return -1;
		}
		*headptr = ptr;
		ptr->link=NULL;
		ptr->data=data;
	}
	else
	{
		//node(s) exist.
		//seek to end of linked list
		node_t *ptr = *headptr;
		while(ptr->link)
		{
			ptr = ptr->link;
		}
		//now ptr points to last valid node.
		ptr->link = (node_t *)malloc(sizeof(node_t));
		if(!(ptr->link))
		{
			printf("cannot allocate memory\n");
			return -1;
		}
		(ptr->link)->link = NULL;
		(ptr->link)->data = data;
	}
	return 0;
}

int main()
{
	node_t *head=NULL;
	
	push(1, &head);
	push(2, &head);
	displist(&head);
}
