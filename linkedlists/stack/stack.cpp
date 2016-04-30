#include<iostream>
#include<stdlib.h>

using namespace std;

class stack_element
{
	friend class stack;
	int data;
	stack_element *link;
	public:
	stack_element()
	{
		data = 0;
		link = NULL;
	}
	stack_element(int d)
	{
		data = d;
		link = NULL;
	}
	stack_element(int d, stack_element *l)
	{
		data = d;
		link = l;
	}
};	


class stack
{
	private:
	stack_element *head;
	public:
	stack();
	~stack();
	int push(int data);
	int pop();
	void display();
};

stack::stack()
{
	head = NULL;
}
int stack::push(int data)
{
	if(head == NULL)
	{
		//first element to be pushed
		stack_element *Se = new stack_element(data);
		if(!Se)
		{
			return -1;
		}
		head = Se;
	}
	else
	{
		//insert at head
		stack_element *Se = new stack_element(data, head);
		head = Se;
	}
	return 0;
}

int stack::pop()
{
	stack_element *Se = head;
	if(!Se)
	{
		//no element in stack.
		//cannot pop.
		//throw exception.
		throw -1;
		//return 0;
	}
	else
	{
		// popping from head
		int ret = Se->data;
		head = Se->link;
		delete Se;
		return ret;
	}
}

void stack::display()
{
	stack_element *Se = head;
	while(Se)
	{
		cout<<Se->data<<' ';
		Se = Se->link;
	}
	cout<<endl;
}
stack::~stack()
{
	stack_element *Se = head;
	stack_element *Se_link = NULL;
	if(head){Se_link = head->link;}
	while(Se)
	{
		delete Se;
		Se = Se_link;
		if(Se_link){Se_link = Se_link->link;}
	}
}

int main()
{
	stack *S  = new stack;
	
	try
	{
		S->push(1);
		S->push(2);
		S->display();
		S->pop();
		S->display();
		S->pop();
		S->display();
		S->pop();
	}
	catch(int e)
	{
		cout<<"cannot pop"<<endl;
	}
	delete S;
}
