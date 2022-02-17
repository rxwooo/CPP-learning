#include<bits/stdc++.h>
#include"token.h"
using namespace std;

int main()
{
	string sy_file;
	if (!read_file2string("test.txt", sy_file))
	{
		cout << "file load error" << endl;
		return 0;
	}
	vector<shared_ptr<Token>> tokens;
	string2tokens(sy_file.c_str(), tokens);
	tokenoutput(tokens);
	
	return 0;
}