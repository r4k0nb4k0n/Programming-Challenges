#include <iostream>
#include <cstring>
#include <algorithm>
#define MAX 10000
using namespace std;

int M, N;
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
    cin >> M >> N;
    int sum = 0, min = MAX;
    for(int i=M; i<=N; i++){
        if(is_prime[i]){
            sum += i;
            min = std::min(min, i);
        }
    }
    if(sum == 0 && min == MAX){
        cout << "-1";
    }
    else{
        cout << sum << "\n" << min;
    }
    return 0;
}