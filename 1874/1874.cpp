#include <iostream>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

vector<int> series;
queue<char> out;
stack<int> st;
int i, n, m=1;

bool is_possible(int first, int second, int third){
    if(first > second && second < third && first > third)
        return false;
    return true;
}

int main(){
    cin >> n;
    series.resize(n);
    for(i=0; i<n; i++) cin >> series[i];
    // 입력
    for(i=2; i<n; i++){
        if(!is_possible(series[i-2], series[i-1], series[i])){
            cout << "NO";
            return 0;
        }
    }
    for(i=0; i<n; i++){
        int gap = series[i] - m;
        if(gap > 0){
            do{
                st.push(m++); out.push('+');
            }while(st.top() != series[i]);
            st.pop(); out.push('-');
        }
        else if(gap < 0){
            while(st.top() != series[i]){
                st.pop(); out.push('-');
            }
            st.pop(); out.push('-');
        }
        else if(gap == 0){
            m++;
            out.push('+');
            out.push('-');
        }
    }
    while(!out.empty()){
        cout << out.front() << "\n";
        out.pop();
    }   
    return 0;
}
