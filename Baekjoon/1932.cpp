#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;
vector<vector<int> > triangle;
vector<vector<int> > memo;

int solve(int row, int col){ 
    // 함수의 정의 : 숫자삼각형의 1행 1열부터 시작해서 마지막 행까지 갈 때 최대가 되는 합을 리턴.
    if(row >= n) return 0;
    // 기저조건
    int& ret = memo[row][col]; if(ret!=-1) return ret;
    // 메모이제이션
    ret = triangle[row][col] + max(solve(row+1, col), solve(row+1, col+1));
    // 점화식
    return ret;
}

int main(){
    cin >> n;
    triangle.resize(n); memo.resize(n);
    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            int input;
            cin >> input;
            triangle[i].push_back(input);
            memo[i].push_back(-1);
        }
    }
    // 입력
    int answer = solve(0, 0);
    // 처리
    cout << answer;
    // 출력
    return 0;
}
