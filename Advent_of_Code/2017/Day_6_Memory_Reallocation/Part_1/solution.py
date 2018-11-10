import copy, time

bank = None
answer = 0
seen = {}
with open('input.txt', 'r') as f:
	bank = [int(i) for i in f.read().split('\t')]

original = copy.deepcopy(bank)

def where_is_most_blocks(bank):
	return bank.index(max(bank))

def redistribute(bank):
	redis_from = where_is_most_blocks(bank)
	redis_to = (redis_from + 1) % len(bank)
	amount = int(bank[redis_from] / (len(bank) - 1)) if bank[redis_from] >= (len(bank) - 1) else 1
	print("From bank[" + str(redis_from) + "] with amount " + str(amount))
	while(redis_from != redis_to):
		bank[redis_to] += amount
		bank[redis_from] -= amount
		if bank[redis_from] == 0:
			amount = 0
		redis_to = (redis_to + 1) % len(bank)
	return bank

print(str(bank) + " Init")
while True:
	bank = redistribute(bank)
	print(bank)
	answer += 1
	if str(bank) in seen:
		print(answer)
		break
	else:
		seen[str(bank)] = '1'