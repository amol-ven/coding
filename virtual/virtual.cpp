#include <iostream>


using namespace std;

class Base
{
	public:
	virtual void func()
	{
		cout<<"BaseFunc\n";
	}
};

class Derived : public Base
{
	public:
	void func()
	{
		cout<<"DerivedFunc\n";
	} 
};

int main()
{
	Base *bptr = new Derived;
	bptr->func();
}
