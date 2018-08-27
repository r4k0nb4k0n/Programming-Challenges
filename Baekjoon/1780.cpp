#include<iostream>
using namespace std;
int n, arr[2200][2200], cnt[3]; // n : 행렬의 크기, arr[2200][2200] : 종이의 각 칸의 값 입력받음, cnt[3] : -1, 0, 1의 집합의 개수.
// 2200인 이유. n의 최대 범위가 3**7 = 2187 이기 때문에.
int chk(int x, int y, int sz) // 함수의 정의 : 종이가 모두 같은 수로 되어 있을 때, 그 수를 리턴.
{
    int start = arr[y][x];
    for (int i = y; i < y + sz; i++)
        for (int k = x; k < x + sz; k++)
            if (arr[i][k] != start) return 2; // 만약 하나라도 다른 수가 나온다면, -1, 0, 1을 제외한 나올 수 없는 값 2를 리턴한다.
    return start; // 모두 같은 수로 되어 있다면, 그 수를 리턴.
}
void cal(int x, int y, int sz) // 함수의 정의 : 행렬을 적절한 크기로 자름.
{
    // 기저 조건.
    if (sz == 1) // 정사각형의 크기가 1일 때
    {
        for (int i = y; i < y + 3; i++)
            for (int k = x; k < x + 3; k++)
                cnt[arr[i][k] + 1]++; // 종이의 각 칸의 값에 대한 개수를 셈. (크기가 1이므로.)
        return; // 재귀함수 종료.
    }
 
    int temp = chk(x, y, sz); // x, y, sz의 값으로 종이가 모두 같은 수로 되어 있다면 그 수를 저장.
    if (temp != 2) cnt[temp + 1]++; // 모두 같은 수로 되어 있다면, 그 정사각형를 한 개로 취급하고 그 수에 대한 집합 개수 1개 증가.
    else // 하나라도 다른 수가 나왔다면
    {
        int nsz = sz / 3; // 2. (1.)이 아닌 경우에는 종이를 같은 크기의 9개의 종이로 자르고, 각각의 잘린 종에 대해 (1.)의 과정을 반복.
        if (nsz == 1) cal(x, y, 1); // 종이를 같은 크기의 9개의 종이로 잘랐을 때, 크기가 1이라면, cal(x,y,1) 수행.
        else
        {
            cal(x, y, nsz);
            cal(x + nsz, y, nsz);
            cal(x + (nsz * 2), y, nsz);
            // 그냥 y일 때.
            cal(x, y + nsz, nsz);
            cal(x + nsz, y + nsz, nsz);
            cal(x + (nsz * 2), y + nsz, nsz);
            // y + nsz 일 때.
            cal(x, y + (nsz * 2), nsz);
            cal(x + nsz, y + (nsz * 2), nsz);
            cal(x + (nsz * 2), y + (nsz * 2), nsz);
            // y + (nsz * 2) 일 때.
        }
    }
    return; // 종료.
}
int main()
{
    cin >> n; // 종이의 크기 입력받음.
    for (int i = 0; i < n; i++)
        for (int k = 0; k < n; k++) cin >> arr[i][k]; // 반복문을 통해 종이의 각 칸의 값들을 입력받음.
    cal(0, 0, n); // 행렬을 적절한 크기로 자름.
    for (int i = 0; i < 3; i++)
        cout << cnt[i] << endl; // 결과값 출력.
    return 0;
}
