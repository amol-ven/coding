#include <iostream>
#include <math.h>

using namespace std;

class shape
{
	protected:
	float area;
	shape();
	public:
	virtual void set(int, int) =0;
	virtual int getArea() =0;
};

class rectangle:public shape
{
	
	int length, width;
	
	public:
	rectangle();
	void set(int l, int w);
	int getArea();
};

shape::shape()
{
	cout<<"Creating shape\n";
}

rectangle::rectangle()
{
	cout<<"Creating rectangle\n";
}
void rectangle::set(int l, int w)
{
	length = l;
	width = w;
	area = l*w;
}

int rectangle::getArea()
{
	return area;
}


int main()
{
	//rectangle R;
	shape *S;
	S = new rectangle;
	S->set(3, 4);
	cout<<S->getArea()<<endl;
}




