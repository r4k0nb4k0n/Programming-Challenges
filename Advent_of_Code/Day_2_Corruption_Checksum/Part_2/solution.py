import sys

spreadsheet = []

# Read input and parse with '\t'
with open('input.txt', 'r') as f:
	spreadsheet = f.readlines()
	for idx, row in enumerate(spreadsheet):
		spreadsheet[idx] = row.lstrip().rstrip().split('\t')
	
answer = 0
for row in spreadsheet:
	for idx, item in enumerate(row):
		item = int(item)
		flag = 0
		for i in range(idx+1, len(row)):
			flag = i
			if i == idx:
				continue
			n = int(row[i])
			if item % n == 0 or n % item == 0:
				answer += int(item / n) if item >= n else int(n / item)
				break
		if flag >= len(row):
			break

print(answer)
