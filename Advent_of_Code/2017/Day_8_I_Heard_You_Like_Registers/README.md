# Day 8: I Heard You Like Registers
## Part 1
### Translation
CPU로부터 직접 신호를 받았다. 최근에 점프 명령어와 관련하여 도움을 준 적이 있기 때문에, 특이한 레지스터 명령어들의 결과를 연산해야 한다.  
  
각 명령어는 여러 부분으로 구성된다: 수정할 레지스터, 레지스터의 값을 증가할지 감소할지의 여부, 증감량, 그리고 조건이다. 만약 조건이 거짓이라면, 레지스터를 수정하지 않고 건너뛴다. 모든 레지스터들은 `0`부터 시작한다. 명령어들은 다음과 같이 생겼다:
```
b inc 5 if a > 1
a inc 1 if b < 5
c dec -10 if a >= 1
c inc -20 if c == 10
```
이 명령어들은 다음과 같이 처리된다:
   - `a`가 `0`부터 시작하기 때문에, `1`보다 크지 않으므로, `b`는 수정되지 않는다.
   - `b(0) < 5`이기 때문에 `a`는 `1`만큼 증가하여 `1`이 된다.
   - `a(1) <= 1`이기 때문에 `c`는 `-10`만큼 감소하여 `10`이 된다.
   - `c == 10`이기 때문에 `c`는 `-20`만큼 증가하여 `-10`이 된다.
  
이러한 과정 후에, 레지스터 중 가장 큰 값은 `1`이다.  
  
조건 연산자로 `<=`나 `!=`도 있다. 하지만 CPU는 레지스터가 얼마만큼 있는지 알려주지 않고, 알아서 결정하도록 한다.  
  
퍼즐 입력에 주어진 명령어들의 실행을 완료한 이후 레지스터 중 가장 큰 값은 무엇인가?
### Solution
- 입력 : 명령어들.
- 처리 : 주어진 조건에 따라 참일 떄 명령어를 실행한다.
- 출력 : 레지스터 중 가장 큰 값.
- [source](./Part_1/solution.py)

## Part 2
### Translation
안전을 위해, CPU는 또한 명령어들을 처리하는 과정 중에 나타나는 가장 큰 값을 알아내어, 이 연산들을 할당하기 위해 얼마나 많은 메모리가 필요한지 결정할 수 있어야 한다. 예를 들어, 위 명령어들에서, 과정 중에 나타나는 가장 큰 값은 `10`이다. (세 번째 명령어가 실행된 후, 레지스터 `c` 안)
### Solution
- 입력 : 명령어들.
- 처리 : 처리 과정 중 나타나는 가장 큰 값을 구한다.
- 출력 : 처리 과정 중 나타나는 가장 큰 값.
- [source](./Part_2/solution.py)