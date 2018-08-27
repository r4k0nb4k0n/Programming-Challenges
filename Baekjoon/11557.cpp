#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> name;
vector<int> liter;

int main(void)
{
    int T;//테스트 케이스 수.
    int N;//학교의 수.
    
    cin >> T;
    for(int i=1;i<=T;i++)
    {
        cin >> N;
        int best = 0; //최고점수.
        int best_num; //최고점수가 저장되는 번호.
    
        name.resize(N+1); // 학교 수만큼 name 리스트 크기 조정.
        liter.resize(N+1); // 학교 수만큼 liter 리스트 크기 조정.
    
        for(int i=1;i<=N;i++)
        {
            cin >> name[i]; // i번째 리스트에 이름 저장.
            cin >> liter[i]; // i번째 리스트에 술 리터 저장.
            if( liter[i] > best )
            {
                best = liter[i];
                best_num = i;
            }
        }
        cout << name[best_num] << endl;
    }
    
    return 0;
}