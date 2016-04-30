#include <iostream>
#include <math.h>

using namespace std;

class complex
{
	protected:
	int Real, Img;
	
	public:
	virtual int getReal(){return Real;}
	virtual int getImg(){return Img;}
	virtual void set(int real, int imaginary);
	virtual float getMag();
	complex();
	complex(int real, int imaginary);
	complex(const complex &c2);
	complex operator+(complex c2);
	int operator=(complex c2);
	
};


class complex3D : public complex
{
	private:
	int Z;
	public:
	void set(int real, int imaginary, int z);
	float getMag();
	complex3D();
	complex3D(int real, int imaginary, int z);
	complex3D(complex c2);
	complex3D operator + (complex3D c2);	
};


void complex::set(int real, int imaginary)
{
	Real = real;
	Img = imaginary;
}

float complex::getMag()
{
	return sqrt(Real*Real + Img*Img);
}

complex::complex()
{
	Real=0;
	Img=0;
	cout<<"default constructor base Complex"<<endl;
}
complex::complex(const complex &c2)
{
	Real = c2.Real;
	Img = c2.Img;
	
	cout<<"copy constructor base Complex Real="<<c2.Real<<endl;
}

complex::complex(int real, int imaginary)
{
	Real=real;
	Img=imaginary;
	cout<<"parameterised constructor base Complex"<<endl;
}

complex complex::operator+(complex c2)
{
	complex ret;
	ret.Real = Real + c2.Real;
	ret.Img = Img + c2.Img;
	return ret;
}

int complex::operator=(complex c2)
{
	Real = c2.Real;
	Img = c2.Img;
	return 1;
}


void complex3D :: set(int real, int imaginary, int z)
{
	Real = real;
	Img = imaginary;
	Z = z;
}

float complex3D :: getMag()
{
	cout<<"3D get MAG: ";
	return sqrt(Real*Real + Img*Img + Z*Z);
}

complex3D::complex3D()
{
	Real=0;
	Img=0;
	Z=0;
	cout<<"default constructor Complex 3D"<<endl;
}
complex3D::complex3D(complex c2)
{
	Real = c2.getReal();
	Img = c2.getImg();
	Z = 0;
	cout<<"2D constructor Complex 3D"<<endl;
}
complex3D::complex3D(int real, int imaginary, int z)
{
	Real=real;
	Img=imaginary;
	Z=z;
	cout<<"parameterised constructor Complex 3D"<<endl;
}

int main()
{
	complex C;
	//complex *B = new complex(5, -3);
	complex B(1, 0);
	C.set(0, 1);
	cout<<C.getMag()<<endl;
	C=C+B;
	cout<<C.getMag()<<endl;
	
	
	complex *D = new complex3D(C);
	cout<<D->getMag();
	
	
}

