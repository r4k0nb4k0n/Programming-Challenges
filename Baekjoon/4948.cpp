#include <iostream>
#include <cstring>
#define MAX 123456*2
using namespace std;

bool is_prime[MAX+1];

void eratos(){
    memset(is_prime, true, sizeof(is_prime));
    is_prime[0] = is_prime[1] = false;
    for(int i=2; i*i<=MAX; i++){
        if(is_prime[i]){
            for(int j=i*i; j<=MAX; j+=i){
                is_prime[j] = false;
            }
        }
    }
    return;
}

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n;
    eratos();
    while(true){
        cin >> n;
        if(n <= 0) break;
        int cnt = 0;
        for(int i=n+1; i<=2*n; i++){
            if(is_prime[i]) cnt+=1;
        }
        cout << cnt << "\n";
    }    
    return 0;
}