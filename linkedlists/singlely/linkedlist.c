#include "linkedlist.h"
#include <stdlib.h>
#include <stdio.h>

node_t *head=NULL, *tail=NULL;


int createFirst(int data, node_t** headptr, node_t **tailptr)
{
	node_t *newnode = (node_t *)malloc(sizeof(node_t));
	if(newnode==NULL)
	{
		printf("cannot allocate memory for new node\n");
		return -1;
	}
	
	newnode->data = data;
	newnode->next = NULL;
	*headptr = newnode;
	*tailptr = newnode;
	
	return 0;
}

int addToHead(int data, node_t **headptr)
{
	node_t *newnode = (node_t *)malloc(sizeof(node_t));
	if(newnode==NULL)
	{
		printf("cannot allocate memory for new node\n");
		return -1;
	}

	newnode->data = data;
	newnode->next = *headptr;
	*headptr = newnode;
	
	return 0;
}

int addToTail(int data, node_t **tailptr)
{
	node_t *newnode = (node_t *)malloc(sizeof(node_t));
	if(!newnode)
	{
		printf("cannot allocate memory for new node\n");
		return -1;
	}
	newnode->data = data;
	newnode->next = NULL;
	(*tailptr)->next = newnode;
	(*tailptr) = newnode;
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

int reverse(node_t **headptr, node_t **tailptr)
{
	node_t *p1=NULL, *p2=NULL, *p3=NULL;
	p1=*headptr;
	if(!p1)
	{
		printf("nullptr");
		return -1;
	}
	
	p2=p1->next;
	if(!p2)
	{
		printf("nullptr");
		return -1;
	}
	
	p1->next = NULL;
	while(p2)
	{
		p3 = p2->next;
		p2->next = p1;
		
		p1=p2;
		p2=p3;
	}
	
	//end of reversal;
	p1 = *headptr;
	//p2 = *tailptr;
	*headptr = *tailptr;
	*tailptr = p1;
	return 0;
}

int main()
{	
	createFirst(0, &head, &tail);
	addToHead(2, &head);
	addToHead(1, &head);
	addToTail(5, &tail);
	displist(&head);
	reverse(&head, &tail);
	displist(&head);
}
