#include<iostream>
#include<stdio.h>
#include<string.h>
#include <fstream>

using namespace std;

int index = 0;			//遍历字符串的当前位置
string str;
int flag=0;
void error();

void E(char t);
void T(char t);
void Ep(char t);
void Tp(char t);
void F(char t);
void A(char t);
void M(char t);

/*		      i      (        )	    +        -	       *        /        $
	    E  "::TE'" ,"::TE'", "null", "null" , "null" , "null" , "null" , "null",
		T  "::FT'" ,"::FT'", "null", "null" , "null" , "null" , "null" , "null",
		E' "null" ,"null", "::ε" , "::ATE'", "::ATE'", "null" , "null" , "::ε" ,
		A  "null" ,"null", "null", "::+"  , "::-"  , "null" , "null" , "null",
		F  "::i",  "::(E)","null", "null" , "null" , "null" , "null" , "null",
		M  "null", "null", "null", "null" , "null" , "::*"  , "::/"  , "null",
		T' "null", "null", "::ε" , "::ε"  , "::ε"  , "::MFT'", "::MFT'", "::ε" ,
*/

void E(char t)
{
	if (t == '(') {
		cout << "E::TE'" << endl;
		T(str[index]);
		Ep(str[index]);
	}
	else if (t == 'i') {
		cout << "E::TE'" << endl;
		T(str[index]);
		Ep(str[index]);
	}
	else {
		error();
		index++;
		E(str[index]);
	}
}

void T(char t)
{
	if (t == 'i') {
		cout << "T::FT'" << endl;
		F(str[index]);
		Tp(str[index]);
	}
	else if (t == '(') {
		cout << "T::FT'" << endl;
		F(str[index]);
		Tp(str[index]);
	}
	else
	{
		error();
		index++;
		T(str[index]);
	}
}

void Ep(char t)
{
	if (t==')')
	{
		cout << "E'::ε" << endl;
	}
	else if (t == '+')
	{
		cout << "E'::ATE'" << endl;
		A(str[index]);
		T(str[index]);
		Ep(str[index]);
	}
	else if (t == '-')
	{
		cout << "E'::ATE'" << endl;
		A(str[index]);
		T(str[index]);
		Ep(str[index]);
	}
	else if (t=='$')
	{
		cout << "E'::ε" << endl;
	}
	else
	{
		error();
		index++;
		Ep(str[index]);
	}
}

void Tp(char t)
{
	if (t == ')')
	{
		cout << "T'::ε" << endl;
	}
	else if (t == '+')
	{
		cout << "T'::ε" << endl;
	}
	else if (t == '-')
	{
		cout << "T'::ε" << endl;
	}
	else if (t == '*')
	{
		cout << "T'::MFT'" << endl;
		M(str[index]);
		F(str[index]);
		Tp(str[index]);
	}
	else if (t == '/')
	{
		cout << "T'::MFT'" << endl;
		M(str[index]);
		F(str[index]);
		Tp(str[index]);
	}
	else if (t == '$')
	{
		cout << "T'::ε" << endl;
	}
	else
	{
		error();
		index++;
		Tp(str[index]);
	}

}

void F(char t) {
	if (t == 'i') {
		cout << "F::i" << endl;
		index++;
	}
	else if (t == '(') {
		cout << "F->(E)" << endl;
		index++;
		E(str[index]);
	}
	else {
		error();
		index++;
		F(str[index]);
	}
}

void A(char t)
{
	if (t == '+')
	{
		cout << "A::+" << endl;
		index++;
	}
	else if (t == '-')
	{
		cout << "A::-" << endl;
		index++;
	}
	else
	{
		error();
		index++;
		A(str[index]);
	}
}

void M(char t)
{
	if(t == '*')
	{
		cout << "M::*" << endl;
		index++;
	}
	else if (t == '/')
	{
		cout << "M::/" << endl;
		index++;
	}
	else
	{
		error();
		index++;
		M(str[index]);
	}
}

void error()
{
	cout << "error-Symbol ignored" << endl;
	flag=1;
}

int main()
{
	cout<<"Parsing beginning\n"<<endl;
    ifstream Prewords("t4.txt", ios::in);
    getline(Prewords, str);

	E(str[index]);
	cout<<"\nParsing completed"<<endl;
	if(flag==1)
    	cout<<"parsing is not legal"<<endl;
    else
        cout<<"parsing is legal"<<endl;
	return 0;
}
