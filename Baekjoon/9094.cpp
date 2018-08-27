#include <iostream>
using namespace std;
int t;
int n, m;
int main(){
    cin >> t;
    while(t--){
        cin >> n >> m;
        int cnt = 0;
        for(int a=1; a<n; a++){
            for(int b=a+1; b<n; b++){
                if((a*a+b*b+m) % (a*b) == 0)
                    cnt++;
            }
        }
        cout << cnt << "\n";
    }
    return 0;
}