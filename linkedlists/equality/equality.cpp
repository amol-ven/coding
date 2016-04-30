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


int compareLists(Node *headA, Node *headB)
{
	int equal = 1;
	while(headA && headB)
	{
		if(headA->getData() != headB->getData())
		{
			equal = 0;
			break;
		}
		headA = headA->getLink();
		headB = headB->getLink();
	}
	if(equal == 0)
	{
		return -1;
	}
	if(headA)
	{
		return headA->getData();
	}
	if(headB)
	{
		return headB->getData();
	}
	return 0;
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
	cout<<"\n\n"<<compareLists(headA, headB)<<endl;
	return 0;
}
