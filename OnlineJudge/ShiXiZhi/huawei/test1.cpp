#include<bits/stdc++.h>
using namespace std;

string BtoL(string str)
{
    for(int i = 0; i < str.size(); i++)
        if(str[i] >= 'A' && str[i] <= 'Z')
            str[i] = str[i] - ('A' - 'a');
    return str;
}

int main()
{
    unordered_map<string, int> _map;
    vector<string> strVec; 
    string sentence;
    char c;
    while(1)
    {
        c = getchar();
        if(c == '\n')
            break;
        sentence += c;
    }
    string str;
    int count = 0;
    while(cin >> str)
    {
        if(_map.find(BtoL(str)) == _map.end())
            _map.insert({BtoL(str), count++});
        else
            _map[BtoL(str)] = count ++;
        c = getchar();
        if(c == '\n')
            break;
    }
    int pos = 0;
    int len = sentence.size();
    while(pos < len)
    {
        if(sentence[pos] == ' ' || sentence[pos] == '.' || sentence[pos] == ',')
        {
            cout << sentence[pos++];
        }
        else if(sentence[pos] == '\"')
        {
            cout << sentence[pos++];
            while(sentence[pos] != '\"')
                cout << sentence[pos++];
            cout << sentence[pos ++];
        }
        else
        {
            string word = "";
            while(sentence[pos] != ' ' && sentence[pos] != '.' && sentence[pos] != ',')
                word += sentence[pos++];
            string post = BtoL(word);
            if(_map.find(post) == _map.end())
            {
                cout << word;
            }
            else
                cout << _map[post];
        }
    }
    cout << endl;
    return 0;
}