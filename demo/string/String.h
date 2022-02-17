#include<bits/stdc++.h>
using namespace std;
#ifndef __String__
#define __String__

class String
{
    friend ostream& operator << ( ostream& os, String& s) { return os << s.data; }
    friend String operator + ( String a, String b);

private:
    char *data;

public:
    String ( char*  );
    String ( const String& );
    ~String();
    String& operator = ( char* );
    String& operator = ( String& );

};

String::String ( char *s = 0 )
{
    if( s )
    {
        data = new char[ strlen( s ) + 1 ];
        strcpy( data, s );
    }
        
    else
    {
        data = new char[1];
        *data = '\0';
    }
}

String::String ( const String& s )
{
    data = new char[ strlen(s.data) + 1 ];
    strcpy( data, s.data );
}

String::~String()
{
    delete[] data;
}

String& String::operator = ( char *s )
{
    if( s == data )
        return *this;
    
    delete[] data;
    data = new char[ strlen( s ) + 1];
    strcpy( data, s);
    return *this;
}

String& String::operator = ( String& s )
{
    if( this == &s )
        return *this;
    
    delete[] data;
    data = new char[ strlen( s.data ) + 1];
    strcpy( data, s.data );
    return *this;
}

String operator + ( String a, String b)
{
    String c;
    c.data = new char[ strlen(a.data) + strlen(b.data) + 1];
    strcpy( c.data, a.data );
    strcpy( c.data + strlen( a.data ), b.data );
    return c;
}

#endif