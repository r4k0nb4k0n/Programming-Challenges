# [1A_Theatre_Square](http://codeforces.com/contest/1/problem/A)

## Summary
* 영화관은 `n × m` 크기의 직사각형 모양이다.
* 판석의 크기는 `a × a`이다.
* `1 ≤ n,m,a ≤ 10^9`
* 영화관 바닥을 덮기 위한 판석의 최소 개수는?
  - 영화관 바닥의 크기보다 더 크게 덮어도 된다.
  - 판석을 쪼개서는 안된다.

## Solution
* 영화관 바닥의 크기보다 더 크게 덮어도 되므로 영화관 바닥의 가로/세로의 길이가 판석의 가로/세로의 길이로 나눠떨어지지 않을 경우 판석 하나 더 붙여준다.
* `((n ÷ a) or (n ÷ a) + 1) × ((m ÷ a) or (m ÷ a) + 1)`
* [source](./solution.cpp)