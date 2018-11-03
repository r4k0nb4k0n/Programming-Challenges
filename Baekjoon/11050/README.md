# [11050번: 이항 계수 1](https://www.acmicpc.net/problem/11050)

## First impression and summary
#### 제한
1 초 / 256 MB

#### 내용
자연수 `N`과 정수 `K`가 주어졌을 때 이항 계수 `(N K)`를 구하는 프로그램을 작성하시오.

#### 입력 및 출력
* `N`과 `K`가 주어진다. (`1≤N≤10, 0≤K≤N`)  
* `(N K)`를 출력한다.

## Trial and error
* 이항 계수
  - 조합론에서, 이항 계수(binomial coefficient)는 주어진 크기의 (순서 없는) 조합의 가짓수이다.
  - `(n k) = `
    + `n!/(k!(n-k)!)` `0≤k≤n`
	+ `0` `k<0`
	+ `0` `k>n`
	+ `n_C_k`
	+ `C(n,k)`
  - `C(n,k) = C(n,n-k)`
  - `C(n,k) + C(n,k+1) = C(n+1,k+1)` -> Pascal's rule

* 이항 계수를 계산하는 함수는 다음과 같고, 이의 시간 복잡도는 대충 `O(n! + k! + (n-k)!)`이다. 최악의 경우 `10! + 10! = 3,628,800 * 2 = 7,257,600` 번의 연산이 필요하다. 시간 초과다. 
```python
def C(n, k):
    a = math.factorial(n)
    b = math.factorial(k)
    c = math.factorial(n-k)
	return a / (b * c)
```

## Solution
* [solution.cpp](./solution.cpp)
* 이는 `0!`부터 `10!`까지의 연산의 결과를 미리 구하여 저장한 다음 사용하는 코드이다. 반복문을 이용하여 계산하므로 이항 계수를 구하는 연산만 제외하면 항상 10번의 연산만이 필요하다.

```python
factorial = [i * i-1 if i<2 else 1 for i in range(11)]

def C(n, k):
    a = factorial[n]
    b = factorial[k]
    c = factorial[n-k]
	return a / (b * c)
```