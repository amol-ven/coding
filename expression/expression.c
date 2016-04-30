#include <stdio.h>
#include <stdlib.h>

#define NUM 1
#define OPR  2

typedef struct node
{
	int type;
	float number;
	char operator;
	struct node *link;
}node_t;

node_t * addNode(node_t **head)
{
	if(*head == NULL)
	{
		node_t *newnode = (node_t *)malloc(sizeof(node_t));
		*head = newnode;
		return newnode;
	}
	else
	{
		node_t *n = *head;
		while(n->link)
		{
			n = n->link;
		}
		node_t *newnode = (node_t *)malloc(sizeof(node_t));
		n->link = newnode;
		return newnode;
	}
}

void display(node_t **head)
{
	node_t *n = *head;
	while(n)
	{
		if(n->type == NUM)
		{
			printf("%f ", n->number);
		}
		else
		{
			printf("%c ", n->operator);
		}
		n = n->link;
	}	
}



int sanity(char *e)
{
	while(*e)
	{
		if( !((*e>='0'&&*e<='9') || *e=='+' || *e=='-' || *e=='*' || *e=='/') )
		{
			return -1;
		}
		e++;
	}
	return 0;
}

int isNumber(char *s)
{	
	if(*s>='0' && *s<='9')
	{
		return 0;
	}
	else
	{
		return -1;
	}
}

int getNumber(char *s)
{
	int num=0;
	while(*s>='0' && *s<='9')
	{
		num = num*10 + ((*s)-'0');
		s++;
	}
	return num;
}

void build(char *exp, node_t **head)
{
	int index=0;
	while(*exp)
	{
		
		if(isNumber(exp)==0)
		{
			//printf("N");
			//add number node
			int num = getNumber(exp);
				
			node_t *newnode = addNode(head);
			newnode->type = NUM;
			newnode->number = num;
			newnode->link = NULL;
			
			while(*exp>='0' && *exp<='9')
			{
				exp++;
			} 
		}
		else
		{
		//	printf("O");
			//add opr node
			node_t *newnode = addNode(head);
			newnode->type = OPR;
			newnode->operator = *exp;
			newnode->link = NULL;
			exp++;
		}
	}
}

int main()
{
	node_t *head = NULL;
	char expr[100];
	printf("Enter expression: ");
	scanf("%s", expr);
	
	printf("sanity = %d\n", sanity(expr));
	
	build(expr, &head);
	
	//printf("\n%d", getNumber(expr));
	
	//display(&head);
	
	node_t *prev, *curr;
	prev = head;
	curr = prev->link;
	
	while(curr)
	{
	///	printf("C");
		if(curr->type == OPR)
		{	
			if(curr->operator == '/' || curr->operator == '*')
			{
				node_t *next = curr->link;
				{	
					if(curr->operator == '/')
					{
						prev->number = prev->number / next->number;
					}
					if(curr->operator == '*')
					{
						prev->number = prev->number * next->number;
					}
					prev->link = next->link;
					curr = next->link;
				}
			}
			else
			{
				prev = curr;
				curr = curr->link;
			}
		}
		else
		{
			prev = curr;
			curr = curr->link;
		}
	}
		
	//display(&head);
	
	
	
	
	
	
	
	
	
	prev = head;
	curr = prev->link;
	
	while(curr)
	{
		//printf("D");
		if(curr->type == OPR)
		{	
			if(curr->operator == '+' || curr->operator == '-')
			{
				node_t *next = curr->link;
				{	
					if(curr->operator == '+')
					{
						prev->number = prev->number + next->number;
					}
					if(curr->operator == '-')
					{
						prev->number = prev->number - next->number;
					}
					prev->link = next->link;
					curr = next->link;
				}
			}
			else
			{
				prev = curr;
				curr = curr->link;
			}
		}
		else
		{
			prev = curr;
			curr = curr->link;
		}
	}
		
	//display(&head);
	
	float final = head->number;
	
	printf("Final = %f\n", final);
	
	
	
	
	
	
	return 0;
}
