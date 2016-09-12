#include <cstdio>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    string first;
    string second;

    cin >> first;
    cin >> second;
    int i = 0;
    while(first[i] != '\0')
    {
        if(first[i] == second[i])
            printf("0");
        else
            printf("1");
        i++;
    }

    return 0;
}
