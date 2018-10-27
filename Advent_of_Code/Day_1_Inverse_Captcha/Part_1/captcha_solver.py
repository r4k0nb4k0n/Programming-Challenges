import sys

captcha = ""

with open('captcha.txt', 'r') as f:
	captcha = f.read()

l = len(captcha)
answer = 0
for i in range(l):
	digit_now = captcha[i]
	digit_next = captcha[i+1 if i<l-1 else 0]
	if digit_now == digit_next:
		answer += int(digit_now)

print(answer)