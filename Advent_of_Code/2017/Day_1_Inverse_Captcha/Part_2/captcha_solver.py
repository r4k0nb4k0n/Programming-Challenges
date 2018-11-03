import sys

captcha = ""

with open('captcha.txt', 'r') as f:
	captcha = f.read()

l = len(captcha)
half_l = int(l/2)
answer = 0
for i in range(l):
	digit_now = captcha[i]
	digit_next = captcha[(i+half_l)%l]
	if digit_now == digit_next:
		answer += int(digit_now)

print(answer)