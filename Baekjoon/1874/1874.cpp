#include <iostream>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

vector<int> series; // 입력 수열
queue<char> out; // 출력 버퍼
stack<int> st; // 스택 시뮬레이션
int i, n, m=1;

int main(){
    cin >> n;
    series.resize(n);
    for(i=0; i<n; i++) cin >> series[i]; // 수열 입력받기
    for(i=0; i<n; i++){ // 스택으로 입력된 수열 만들기
        int gap = series[i] - m;
        if(gap > 0){
            do{
                st.push(m++); out.push('+');
            }while(st.top() != series[i]);
            st.pop(); out.push('-');
        }
        else if(gap < 0){
            while(!st.empty() && st.top() != series[i]){
                st.pop(); out.push('-');
            }
            if(st.empty()){ // 입력된 수열을 만들 수 없는 경우
                cout << "NO";
                return 0;
            }
            st.pop(); out.push('-');
        }
        else if(gap == 0){
            m++;
            out.push('+');
            out.push('-');
        }
    }
    while(!out.empty()){ // 출력 버퍼 비우기
        cout << out.front() << "\n";
        out.pop();
    }   
    return 0;
}
