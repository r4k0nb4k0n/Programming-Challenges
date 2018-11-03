import sys

spreadsheet = []

# Read input and parse it with '\t'
with open('input.txt', 'r') as f:
	spreadsheet = f.readlines()
	for idx, row in enumerate(spreadsheet):
		spreadsheet[idx] = row.lstrip().rstrip().split('\t')
	
answer = 0
for row in spreadsheet:
	minimum = 5000
	maximum = -1
	for item in row:
		item = int(item)
		minimum = minimum if item > minimum else item
		maximum = maximum if item < maximum else item
	difference = maximum - minimum
	answer += difference

print(answer)
	