#ifndef _Complex_
#define _Complex_

#include <bits/stdc++.h>
using namespace std;

class Complex
{
public:
	//Complex() { shi = 10, xu = 10; }
	Complex(double x=0,double y=0): shi(x) , xu(y) {}
	Complex(const Complex& c) { cout<<"build"<<endl; shi = c.shi; xu = c.xu; }
	double gs () const { return shi; }
	double gx () const { return xu; }
	void wx (double x) { xu=x;  }
	void ws (double s) { shi=s; }
	Complex& operator += ( const Complex);
	Complex& operator += ( double &);
	Complex& operator -= ( const Complex& );
	Complex& operator -= ( double& );
	Complex& operator *= ( const Complex& );
	Complex& operator *= ( double& );
	Complex& operator /= ( const Complex& );
	Complex& operator /= ( double& );
	Complex& operator ++ ();
	Complex operator ++ (int);
private:
	double xu; double shi;

	friend Complex& __doapl ( Complex*, const Complex& );
	friend ostream& operator << ( ostream& os, const Complex& c );
	friend istream& operator >> ( istream& is, Complex& c );
	friend Complex operator + ( const Complex& c1, const Complex& c2 );
};

inline Complex& Complex::operator ++ () 
{ 
	shi++; xu++; return *this;
}
inline Complex Complex::operator ++ (int) 
{ 
	Complex temp=*this; shi++; xu++; return temp;
}
inline Complex operator + ( double x, const Complex& r )
{
	return Complex ( r.gs () + x, r.gx () );
}
inline Complex operator + ( const Complex& r,double x)
{
	return Complex ( r.gs () + x, r.gx () );
}
inline Complex operator + ( const Complex& s, const Complex& r )
{
	return Complex ( r.gs () + s.gs(), r.gx ()+s.gx() );
}
inline Complex operator - ( double x, const Complex& r )
{
	return Complex ( x- r.gs () , r.gx () );
}
inline Complex operator - (const Complex& r, double x )
{
	return Complex ( r.gs () - x, r.gx () );
}
inline Complex operator - ( const Complex& r, const Complex& s)
{
	return Complex ( r.gs () - s.gs (), r.gx () - s.gx () );
}
inline Complex operator * ( const Complex& r, double x )
{
	return Complex ( r.gs () * x, r.gx () * x );
}
inline Complex operator *( double x, const Complex& r )
{
	return Complex ( r.gs () * x, r.gx () * x );
}
inline Complex operator * (const Complex& r, const Complex& s )
{
	return Complex ( r.gs () * s.gs () + r.gx () * s.gx (), r.gx () * s.gs () + r.gs () * s.gx () );
}
inline Complex operator / ( const Complex& r, const Complex& s )
{
	return Complex ( (r.gs () * s.gs () + s.gx () * r.gx ()) / (s.gs () * s.gs () + s.gx () * s.gx ()), (-r.gs () * s.gx () + s.gs () * r.gx ()) / (s.gs () * s.gs () + s.gx () * s.gx ()) );
}
inline Complex operator / ( const Complex& r, double x )
{
	return Complex ( r.gs () / x, r.gx () / x );
}
inline Complex operator / ( double x, const Complex& s )
{
	return Complex ( (x* s.gs ()) / (s.gs () * s.gs () + s.gx () * s.gx ()), (-x * s.gx ()) / (s.gs () * s.gs () + s.gx () * s.gx ()) );
}

inline Complex& Complex::operator += ( const Complex r )
{
	shi += r.gs ();
	xu += r.gx ();
	return *this;
}
inline Complex& Complex::operator += ( double& r )
{
	this->shi += r;
	return *this;
}
inline Complex& Complex::operator -= ( const Complex& r )
{
	this->shi -= r.gs ();
	this->xu -= r.gx ();
	return *this;
}
inline Complex& Complex::operator -= ( double& r )
{
	this->shi -= r;
	return *this;
}
inline Complex& Complex::operator *= ( const Complex& s )
{
	this->shi = this->gs () * s.gs () + this->gx () * s.gx ();
	this->xu = this->gx ()* s.gs () + this->gs () * s.gx ();
	return *this;
}
inline Complex& Complex::operator *= ( double& r )
{
	this->shi *= r;
	this->xu *= r;
	return *this;
}
inline Complex& Complex::operator /= ( const Complex& s )
{
	this->shi = (this->gs () * s.gs () + s.gx () * this->gx ()) / (s.gs () * s.gs () + s.gx () * s.gx ());
	this->xu =(-this->gs () * s.gx () + s.gs () * this->gx ()) / (s.gs () * s.gs () + s.gx () * s.gx ());
	return *this;
}
inline Complex& Complex::operator /= ( double& r )
{
	this->shi /= r * 1.0;
	this->xu /= r * 1.0;
	return *this;
}
ostream& operator << ( ostream& os, const Complex & x )
{
	return os << '(' << x.shi << ',' <<x.xu << ')';
}

istream& operator >> ( istream& is,Complex& c )
{
	return is >> c.shi >> c.xu;
}

#endif