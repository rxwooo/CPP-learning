#include<bits/stdc++.h>
using namespace std;


int main()
{
    string day1, day2;   
    string min1, min2;
    cin >> day1 >> day2 >> min1 >> min2;

    int day = 0;
    int hour = -1;
    int mins;

    int pos = 0;
    int flag = 1;
    int count = 0;
    int len = min(day1.size(), day2.size());
    while(pos < len)
    {
        if(day1[pos] == day2[pos])
        {
            if(!flag && ((day1[pos] >= '0' && day1[pos] <= '9') || (day1[pos] >= 'A' && day1[pos] <= 'N')))
            {
                if(day1[pos] >= '0' && day1[pos] <= '9')
                    hour = day1[pos] - '0';
                else if(day1[pos] >= 'A' && day1[pos] <= 'Z')
                    hour = day1[pos] - 'A' + 10;
                break;
            }
            if(flag && day1[pos] >= 'A' && day1[pos] <= 'G')
            {
                day = day1[pos] - 'A' + 1;
                flag = 0;
            }
        }
        pos ++;
    }
    len = min(min1.size(), min2.size());
    pos = 0;
    while (pos < len)
    {
        if(min1[pos] == min2[pos] && ((min1[pos] >= 'a' && min1[pos] <= 'z') || (min1[pos] >= 'A' && min1[pos] <= 'Z')))
        {
            mins = pos;
            break;
        }
        pos ++;
    }
    switch(day)
    {
        case 1: cout << "MON" << " "; break;
        case 2: cout << "TUE" << " "; break;
        case 3: cout << "WED" << " "; break; 
        case 4: cout << "THU" << " "; break; 
        case 5: cout << "FRI" << " "; break; 
        case 6: cout << "SAT" << " "; break; 
        case 7: cout << "SUN" << " "; break;
        default: ;
    }
    if(hour < 10)
        cout << "0" << hour << ":";
    else
        cout << hour << ":";
    if(mins < 10)
        cout << "0" << mins << endl;
    else
        cout << mins << endl;
    return 0;
}