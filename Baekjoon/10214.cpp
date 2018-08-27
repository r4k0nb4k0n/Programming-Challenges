#include <stdio.h>
#include <iostream>
 
using namespace std;
 
int main(void)
{
    int T; // 테스트 케이스의 수.

    cin >> T;
     
    while(T--)
    {
        int Y=0;
        int K=0;
        int temp;
         
        for(int i=1;i<=9;i++)
        {
            cin >> temp;
            Y = Y + temp;
            cin >> temp;
            K = K + temp;
        }
         
        if(Y > K)
            cout << "Yonsei" << endl;
        else if(K > Y)
            cout << "Korea" << endl;
        else
            cout << "Draw" << endl;
    }
     
    return 0;
}