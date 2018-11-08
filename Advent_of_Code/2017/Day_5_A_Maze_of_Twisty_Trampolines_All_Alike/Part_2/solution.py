instructions = []
with open('input.txt', 'r') as f:
	for line in f:
		instructions.append(int(line))
	
prev = 0
pc = 0
steps = 0
while pc in range(len(instructions)):
	prev = pc
	pc += instructions[pc]
	if instructions[prev] >= 3:
		instructions[prev] -= 1
	else:
		instructions[prev] += 1
	steps += 1
	
print("FIND THE EXIT OF THE MAZE!!! " + str(steps) + " has taken.")