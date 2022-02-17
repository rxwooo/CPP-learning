#include<bits/stdc++.h>
using namespace std;

template<class T>
class Array
{
public:
    Array( int sz = 50 ) { assert( sz > 0 ); size = sz; list = new T[ size ]; }
    Array( const Array<T>& a );
    ~Array() { delete[] list; }

    Array<T>& operator = ( Array<T>& a);
    operator T* () { return list; }
    operator T* () const { return list; }
    T& operator [] ( int n ) { assert( n >= 0 && n < size); return list[n]; }
    const T& operator [] ( int n ) const { assert( n >= 0 && n < size ); return list[n]; }
    int getsize () const { return size; }
    void resize ( int n );
    float average () ;

private:
    T* list;
    int size;

    //friend ostream& operator << (ostream& os ,Array& a) { for(int i=0;i<a.size;i++) os<<a[i]<<" "; return os;  }
};

template<class T>
Array<T>::Array( const Array<T>& a )
{
    size = a.getsize();
    list =new T[size];
    for(int i=0;i<size;i++) list[i]=a[i];
}

template<class T>
Array<T>& Array<T>:: operator = ( Array<T>& a)
{
    size = a.getsize();
    list =new T[size];
    for(int i=0;i<size;i++) list[i]=a[i];
    return *this;
}

template<class T>
void Array<T>::resize ( int n )
 { 
    assert(n>=0); 
    int min=n<size?n:size; 
    size=n; T*newlist=new T[n]; 
    for(int i=0;i<min;i++) newlist[i]=list[i];
    delete[] list; 
    list=newlist; 
}

template<class T>
float Array<T>:: average ()
{
    float sum=0;
    for(int i=0;i<getsize();i++) sum+=list[i];
    return sum*1.0/getsize();
}


int main()
{
    int num;
    cout<<"please input the number of student(s) :";
    cin>>num;
    Array<float> grade(num);
    for(int i=0;i<num;i++) 
    {
        cout<<"please input the grade of student "<<i+1<<" :";
        cin>>grade[i];
    }
    cout<<"the average of grade is "<<grade.average()<<endl;

    return 0;
}