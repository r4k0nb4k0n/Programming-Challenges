/* Programming-Challenges
 * Baekjoon
 * 1016
 * 2018-11-05 r4k0nb4k0n
 */

#include <iostream>
#include <cstring>
#define SIZE 1000000+1

using namespace std;
typedef unsigned long long ull;

bool isSqrdNoNo[SIZE];
ull l, h;
int cnt = 0;

int main() {
    memset(isSqrdNoNo, true, sizeof(isSqrdNoNo));
    cin >> l >> h; 
    for(ull i = 2; i*i<=h; i++){
        ull j = l / (i*i);
        if(j*i*i != l) j++;
        for(; j*i*i <= h; j++){
            isSqrdNoNo[j*i*i - l] = false;
        } 
    }
    for(int i=0; i<h-l+1; i++){
        if(isSqrdNoNo[i]) cnt++;
    }
    cout << cnt;
    return 0;
}