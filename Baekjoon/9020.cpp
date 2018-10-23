#include <iostream>
#include <cstring>
#define MAX 10000
using namespace std;

int T;
int n;
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
    eratos();
    cin >> T;
    while(T--){
        cin >> n;
        int guess = int(n/2)+1;
        while(guess--){
            int a = guess;
            int b = n-guess;
            if(is_prime[a] && is_prime[b]){
                cout << a << " " << b << "\n";
                break;
            }
        }
    }    
    return 0;
}