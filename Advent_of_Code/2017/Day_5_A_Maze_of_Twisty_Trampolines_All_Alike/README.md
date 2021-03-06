# Day 5: A Maze of Twisty Trampolines, All Alike
## Part 1
### Translation
CPU로부터 긴급한 새치기(interrupt)가 도착한다: 건너뛰기 명렁들(jump instruction) 미로에 갇혔고, 탈출구를 찾기 위해 여분의 사이클을 이용하여 다른 프로그램들로부터 도움을 받길 원한다.  
  
메시지에는 각 건너뛰기(jump)의 오프셋들의 목록이 포함된다. 건너뛰기들(Jumps)은 상대적이다: `-1`은 이전 명령으로 이동하고, `2`는 다음 명령으로 넘어간다. 목록의 첫 명렁부터 시작한다. 목표는 목록 밖으로 나갈 때까지 건너뛰기들(jumps)을 따라가는 것이다.  
  
게다가, 이 명령들은 조금 이상하다; 각 건너뛰기(jump) 이후, 해당 명령의 오프셋이 `1`씩 증가한다. 따라서, 오프셋 `3`을 만나면, 3개의 명령을 넘어가지만, 이후에 해당 오프셋은 `4`가 된다.  
  
예를 들어, 다음 건너뛰기 오프셋들의 목록을 보자:
```
0
3
0
1
-3
```
양수인 건너뛰기들 ("앞쪽") 아래로 이동한다; 음수인 건너뛰기들은 위로 이동한다. 이 예제의 읽기 쉬움을 위해 말하자면, 이 오프셋 값들은 한 줄에 쓰여지고, 현재 명령은 괄호로 강조될 것이다. 탈출구을 찾기 전까지 다음 단계들이 진행된다:  
   - `(0) 3 0 1 -3` - **맨 처음 상태**
   - `(1) 3 0 1 -3` - 오프셋 `0`만큼 건너뛴다(즉, 전혀 건너뛰지 않는다). 해당 명령은 `1`로 증가한다.
   - `2 (3) 0 1 -3` - 방금 수정한 명령 때문에 앞으로 이동한다. 해당 명령은 다시 `2`로 증가한다.
   - `2 4 0 1 (-3)` - 맨 끝으로 건너뛴다; 뒤에 해당 명령은 `4`로 증가한다.
   - `2 (4) 0 1 -3` - 뒤로 `3`칸 건너뛴다; `-3`은 `-2`로 증가한다.
   - `2 5 0 1 -2` - 앞으로 `4`칸 건너뛰어 미로를 탈출한다.
  
이 예제에서, `5`단계만에 탈출구를 찾았다.  
주어진 퍼즐 입력에서는 몇 단계가 걸리는가?
### Solution
- 입력 : 오프셋 목록
- 처리 : 주어진 오프셋대로 건너뛰어본다. 건너뛴 이후 이전 오프셋은 `1`씩 증가한다. 탈출할 때까지 걸리는 단계 수를 센다.
- 출력 : 탈출할 때까지 걸리는 단계 수.
- [source](./Part_1/solution.py)

## Part 2
### Translation
이제, 건너뛰기가 좀 더 이상해진다: 각 건너뛰기 이후, 오프셋이 **`3` 이상이라면**, `1`씩 **감소**한다. 그렇지 않다면, 전과 같이 `1`씩 증가한다.  
  
위 예제에 바뀐 규칙을 적용한다면, `10`단계가 걸릴 것이고, 탈출 이후 오프셋 값들은 `2 3 2 3 -1`로 남겨진다.  
  
바뀐 규칙일 때 몇 단계가 걸리는가?
### Solution
- 입력 : 오프셋 목록
- 처리 : 주어진 오프셋대로 건너뛰어본다. 이전 오프셋이 `3` 이상이라면 `1`씩 감소하고, 그렇지 않다면 `1`씩 증가한다. 탈출할 때까지 걸리는 단계 수를 센다.
- 출력 : 탈출할 때까지 걸리는 단계 수.
- [source](./Part_2/solution.py)