#include<bits/stdc++.h>
using namespace std;

template<class T>
void exchange(list<T>& l1,typename list<T>::iterator p1,list<T>& l2,typename list<T>::iterator p2)
{
	list<T> temp(p1, l1.end());
    l1.erase(p1, l1.end());

    list<T> temp2(p2, l2.end());
    l2.erase(p2, l2.end());

    l1.insert(l1.end(), temp2.begin(), temp2.end());
    l2.insert(l2.end(), temp.begin(), temp.end());
}

int main()
{
	ostream_iterator<int> output (cout," ");
	list<int> test1 = { 1,2,3,4,5,6,7,8,9,10 };
	list<int> test2 = { 10,9,8,7,6,5,4,3,2,1 };

	cout<<"before exchange:"<<endl;
	copy(test1.begin(),test1.end(),output);
    cout<<endl;
	copy(test2.begin(),test2.end(),output);
    cout<<endl;

	list<int>::iterator t1=test1.begin();
	for(int i=0;i<5;i++) t1++;
	list<int>::iterator t2=test2.begin();
	for(int i=0;i<5;i++) t2++;
	exchange(test1,t1,test2,t2);
	cout<<endl;

	cout<<"after exchange:"<<endl;
	copy(test1.begin(),test1.end(),output);
    cout<<endl;
	copy(test2.begin(),test2.end(),output);
    cout<<endl;

}