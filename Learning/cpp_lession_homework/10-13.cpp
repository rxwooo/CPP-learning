#include<bits/stdc++.h>
using namespace std; 

int rd()
{
    return rand()%9;
}

int power(int x, int y) 
{
    long long re = 1;
    while (y--)  re *= x; 
    return re;
}

int main()
{
    srand(time(NULL));
	vector<int> c1(10);
    ostream_iterator<int> output (cout," ");
	
	generate(c1.begin(),c1.end(),rd);
    copy(c1.begin(),c1.end(),output);
    cout<<endl;

    transform(c1.begin(),c1.end(),output,bind(power, 5, placeholders::_1));
    cout<<endl;

    transform(c1.begin(),c1.end(),output,bind(power, placeholders::_1, 7));
    cout<<endl;

    transform(c1.begin(),c1.end(),output,bind(power, placeholders::_1, placeholders::_1));
    cout<<endl;

    return 0;
}