instructions = None
registers = {}

# Parsing.
with open('input.txt', 'r') as f:
	instructions = [instruction.split(' ') for instruction in f.readlines()]
	instructions = [
		{
			'execution': {
				'register': instruction[0],
				'opcode': instruction[1],
				'amount': int(instruction[2])
			},
			'condition': {
				'register': instruction[4],
				'operator': instruction[5],
				'amount': int(instruction[6])
			}
		} for instruction in instructions
	]

# Do instructions.
for instruction in instructions:
	execution = instruction['execution']
	condition = instruction['condition']
	
	# Initialize registers with 0.
	if execution['register'] not in registers:
		registers[execution['register']] = 0
	if condition['register'] not in registers:
		registers[condition['register']] = 0
	
	# Generate condition string.
	condition = 'registers[\'' + condition['register'] + '\'] ' + condition['operator'] + ' ' +  str(condition['amount'])
	
	# I know it is dangerous, but I have to use `eval()` function.
	if eval(condition):
		print(condition)
		if execution['opcode'] == 'inc':
			registers[execution['register']] += execution['amount']
		elif execution['opcode'] == 'dec':
			registers[execution['register']] -= execution['amount']

# Get the name of the register that has the largest value among them.
largest_register = max(registers, key=registers.get)

print(largest_register, registers[largest_register])