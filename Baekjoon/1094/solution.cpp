/* Programming-Challenges
 * Baekjoon
 * 1094
 * 2018-11-05 r4k0nb4k0n
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> stick;
int X;

int sum_of_sticks(){
    int sum = 0;
    for (int i : stick){
        sum += i;
    }
    return sum;
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> X;

	// 지민이가 가지고 있는 막대의 길이를 모두 더한다.
	// 처음에는 64cm 막대 하나만 가지고 있다.
	// 이때, 합이 X보다 크다면, 아래와 같은 과정을 반복한다.
	stick.push_back(64);
    while (sum_of_sticks() != X){
		// 1. 가지고 있는 막대 중 길이가 가장 짧은 것을 절반으로 자른다.
        sort(stick.begin(), stick.end());
        int half = stick[0] / 2;
        stick[0] /= 2;
		// 2. 만약, 위에서 자른 막대의 절반 중 하나를 버리고 남아있는 막대의 길이의 합이
		// X보다 크거나 같다면, 
        if (sum_of_sticks() >= X){
			// 위에서 자른 막대의 절반 중 하나를 버린다.
            continue;
        }
        else{
            stick.push_back(half);
        }
    }
	
	// 이제, 남아있는 모든 막대를 풀로 붙여서 Xcm를 만든다.

    cout << stick.size();

    return 0;
}