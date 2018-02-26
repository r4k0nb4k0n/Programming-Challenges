# [1874번: 스택 수열](https://www.acmicpc.net/problem/1874)
## Log
- 2018/02/27 0451 : Runtime Error. Trying to remove `array index out of bound` or something.
- 2018/02/27 0456 : Correct.

## How to solve
When I faced this problem first time, I was trying to get some rules/patterns from inputs. **BUT** it is not complex at all. **Keep it simple**.
- Use a stack for processing the series.
- Start `m` with 1. It's a number to push in the stack.
- Loop in the series.
  - Define `gap` as `series[i] - m`.
  - If `gap > 0`, keep pushing `m` in the stack and increasing `m` with `1` until reaching `series[i]`. And pop from the stack just once.
  - If `gap < 0`, keep poping from the stack until reaching `series[i]`. **If the stack is empty, it's IMPOSSIBLE to make the series with stack**.
  - If `gap == 0`, push once, pop once, and increase `m` with `1`.
