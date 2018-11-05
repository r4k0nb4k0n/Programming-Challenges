# Day 1 : Inverse Captcha
## Part One 
### Translation
크리스마스 전날 밤, 산타의 요정들 중 한 명이 당황한 목소리로 당신을 불렀다. "프린터가 고장났어! *착한 아이와 나쁜 아이* 목록을 뽑을 수 없다구!" 당신이 지하 17층에 닿을 즈음, 자정까지 몇 분도 채 남지 않았다. "아주 큰 문제가 있어, " 그녀가 말한다; "분명 시스템에 50개 정도의 버그가 있어야 하는데, 이게 없으면 *목록*을 출력할 수 없다구. 이 사각형에 서, 어서! 설명할 시간이 없다구; 너가 **별**을 내서 그들을 확신시킬 수 있다면, 넌 곧 --" 그녀가 레버를 당기고 세계는 흐려진다.  
  
당신의 눈에 다시 초점이 잡히자, 모든 게 깨진 픽셀처럼 보였다. 그녀가 당신을 컴퓨터 안으로 보냈음에 틀림없다. 당신은 시계를 확인했다: *자정까지 25 밀리초 남음*. 그 많은 시간 안에, 12월 25일까지 모든 **50개의 별들**을 모을 수 있어야 한다.  
  
퍼즐들을 풀어서 별들을 수집해라. 출현 달력의 매 밀리초마다 2개의 퍼즐들이 뜰 것이다; 첫 번째 퍼즐을 풀어야 두 번째 퍼즐을 풀 수 있따. 각 퍼즐마다 **별 한 개**를 얻을 수 있다. 행운을 빈다!  
  
당신은 벽에 "디지털화 검역"이 LED로 수놓인 방에 서 있습니다. 유일한 문은 잠겨 있지만, 작은 장치가 있습니다. "제한 구역 - 디지털화된 사용자는 허용되지 않습니다."  
  
그것은 당신이 **캡차**를 풀어 인간이 아니라는 것을 증명함으로서 탈출할 수 있다는 것을 설명했다. 당연히, 캡차를 풀 수 있는 시간은 1 밀리초다 : 보통 인간에게는 매우 빠르지만, 당신에겐 몇 시간처럼 느껴질 것이다.  
  
캡차는 수열(당신의 퍼즐 입력)을 분석하고 자신의 다음 위치의 수와 일치하는 모든 수들의 합을 찾는 것을 요구한다. 해당 수열은 순환성이 있어서, 마지막 수의 다음 위치의 수는 수열의 첫번째 수이다.  
  
예시:  
   - `1122`는 `3`이다. 1, 2번째 숫자(`1`)와 3, 4번째 숫자(`2`)가 일치하기 때문이다.
   - `1111`은 `4`이다. 각 숫자(모두 `1`)가 그 다음 숫자와 일치하기 때문이다.
   - `1234`는 `0`이다. 아무 숫자도 그 다음 숫자와 일치하지 않기 때문이다.
   - `91212129`는 `9`이다. 마지막 숫자 `9`가 그 다음 숫자와 일치하기 때문이다.
  
이 캡차에 대한 해답은 무엇인가?  
  
### Solution
- 입력 : 10진수 수열
- 처리 : 다음 숫자와 일치하는 숫자의 합을 구한다. 맨 마지막 숫자일 경우 맨 처음 숫자와 비교한다(순환성).
- 출력 : 다음 숫자와 일치하는 숫자의 합.
- [source](./Part_1/captcha_solver.py)

## Part Two
### Translation
당신은 진행율이 50%로 뛰어 오른 것을 확인했다. 문은 열리지 않았지만, 보상으로 **별**을 주었다. 명령은 다음과 같이 바뀌었다:  
  
*다음* 숫자를 고려하는 대신, 순환성이 있는 수열의 절반 길이만큼 떨어진 숫자를 고려한다. 즉, 수열의 길이가 `10`이면, `10/2=5` 단계만큼 앞에 있는 숫자를 고려한다. 운이 좋게도, 주어지는 수열은 짝수 길이다.  
  
예시:
   - `1212`는 `6`이다. 수열의 길이는 4이고, 모든 4개의 숫자가 2개 앞의 숫자와 일치한다.
   - `1221`은 `0`이다. 모두 `1`과 `2`가 만나 일치하지 않기 때문이다.
   - `123425`는 `4`이다. 두 개의 `2`만 서로 일치하기 때문이다.
   - `123123`은 `12`이다.
   - `12131415`는 `4`이다.

이 캡차에 대한 해답은 무엇인가?  

### Solution
- 입력 : 10진수 수열
- 처리 : 수열 길이의 절반만큼 앞서있는 숫자와 일치하는 숫자의 합을 구한다. 순환성을 고려하여 나머지 연산을 활용한다.
- 출력 : 수열 길이의 절반만큼 앞서있는 숫자와 일치하는 숫자의 합
- [source](./Part_2/captcha_solver.py)