#include <iostream>
#include <stdlib.h>

using namespace std;

typedef struct node
{
	struct node *left, *right;
	int data;
}Node;

/*
int addL(Node *n, int data)
{
	if(n)
	{
		if(n->left == NULL)
		{
			Node *newnode = (Node *)malloc(sizeof(Node));
			if(!newnode)
			{
				return -3;
			}
			newnode->left = NULL;
			newnode->right = NULL;
			newnode->data = data;
			n->left = newnode;
		}
		else
		{
			return -2;
		}
	}
	else
	{
		return -1;
	}
	return 0;
}

int addR(Node *n, int data)
{
	if(n)
	{
		if(n->right == NULL)
		{
			Node *newnode = (Node *)malloc(sizeof(Node));
			if(!newnode)
			{
				return -3;
			}
			newnode->left = NULL;
			newnode->right = NULL;
			newnode->data = data;
			n->right = newnode;
		}
		else
		{
			return -2;
		}
	}
	else
	{
		return -1;
	}
	return 0;
}
*/

typedef struct qd
{
	Node *qnode;
	struct qd *next;
}queueData;

int enqueue(queueData **queueStart, Node *qnode)
{
	queueData *prev = NULL;
	queueData *curr = *queueStart;
	while(curr)
	{
		prev = curr;
		curr = curr->next;
	}
	if(prev)
	{
		//cout<<"bb";
		queueData *newqd = (queueData *)malloc(sizeof(queueData));
		if(newqd == NULL)
		{
			return -1;
		}
		prev->next = newqd;
		newqd->next = NULL;
		newqd->qnode = qnode;
		
		//cout<<prev->qnode->data;
	}
	else
	{
		//cout<<"hi";
		prev = (queueData *)malloc(sizeof(queueData));
		if(prev == NULL)
		{
			return -1;
		}
		*queueStart = prev;
		prev->next = NULL;
		prev->qnode = qnode;
	}
	return 0;	
}


Node *dequeue(queueData **queueStart)
{
	if(*queueStart)
	{
		Node *ret = (*queueStart)->qnode;
		queueData *nextqd = (*queueStart)->next;
		free(*queueStart);
		(*queueStart) = nextqd;
		return ret;
	}
	else
	{
		return NULL;
	}
}


Node * bfs(Node *head, int data)
{
	
}


int main()
{
	Node n1, n2, n3, n4, n5, n6, n7;
	
	n1.data = 1;
	n1.left = &n2;
	n1.right = &n3;
	
	n2.data = 2;
	n2.left = &n4;
	n2.right = &n5;
	
	n3.data = 3;
	n3.left = &n6;
	n3.right = &n7;
	
	n4.left = NULL;
	n4.right = NULL;

	n5.left = NULL;
	n5.right = NULL;
	
	n6.left = NULL;
	n6.right = NULL;

	n7.left = NULL;
	n7.right = NULL;
	
	
	queueData *start = NULL;
	cout<<enqueue(&start, &n1);
	enqueue(&start, &n2);
	
	Node *dqed = dequeue(&start);
	//dqed = dequeue(&start);
	cout<<dqed->data<<endl;
	//cout<<((start)->qnode)->data;
}


