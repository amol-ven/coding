#include <iostream>
#include <stdlib.h>

using namespace std;

class Node
{
	private:
	int data;
	Node *link;
	
	public:
	Node();
	Node(int d);
	Node(int d, Node *l);
	int getData();
	Node *getLink();
	void setData(int d);
	void setLink(Node *l);
};

Node::Node()
{
	data = 0;
	link = NULL;
}

Node::Node(int d)
{
	data = d;
	link = NULL;
}

Node::Node(int d, Node *l)
{
	data = d;
	link = l;
}

int Node::getData()
{
	return data;
}

Node * Node::getLink()
{
	return link;
}

void Node::setData(int d)
{
	data = d;
}

void Node::setLink(Node *l)
{
	link = l;
}


void reverse(Node **head)
{
	/*
	if()
	if((*head)->getLink() == NULL)
	{
		return;
	}
	
	
	Node *p1, *p2, *p3;
	
	p1 = *head;
	p2 = p1->getLink();
	p3 = p2->getLink();
	
	p1->setLink(NULL);
	if(p3 == NULL)
	{
		p2->setLink(p1);
		*head = p2;
		return;
	}
	while(p3->getLink())
	{
		
		p2->setLink(p1);
		
		p1 = p2;
		p2 = p3;
		
		p3 = p3->getLink();
	}
	
	p2->setLink(p1);
	p3->setLink(p2);
	
	*head = p3;
	//cout<<head->getData();
	*/
	
	Node *p1, *p2, *p3;
	p1 = NULL;
	
	p2 = *head;
	
	while(p2)
	{
		p3 = p2->getLink();
		p2->setLink(p1);
		
		p1 = p2;
		p2 = p3;
	}
	
	*head = p1;
}


int dispList(Node *head)
{
	while(head)
	{
		cout<<head->getData()<<" ";
		head = head->getLink();
	}
	cout<<endl;
		
}

int main()
{
	Node N1, N2, N3;
	Node M1, M2, M3;
	
	M1 = Node(1, &M2);
	M2 = Node(2 ,&M3);
	M3 = Node(3, NULL);
	
	N1 = Node(1, &N2);
	N2 = Node(2 ,&N3);
	N3 = Node(3, NULL);
	
	Node *headA = &N1, *headB = &M1;
	
	dispList(headA);
	reverse(&headA);
	dispList(headA);
	//cout<<"\n\n"<<compareLists(headA, headB)<<endl;
	return 0;
}
