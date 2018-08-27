#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <climits>
#include <functional>
#include <string>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

typedef pair<int, int> _int;

// written by dj910401

int main(void)
{
    string s;
    cin >> s;

    int ans = 0;
    int temp = 0;
    for(int i=0;i<s.size();i++)
    {
        if(s[i] == ',')
        {
            ans += temp;
            temp = 0;
        }
        else
        {
            temp *= 10;
            temp += (s[i]-'0');
        }
    }
    ans += temp;


    cout << ans;

    return 0;
}
