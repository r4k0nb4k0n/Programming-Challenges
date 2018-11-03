count = 0
passphrases = None
with open('input.txt', 'r') as f:
	passphrases = f.read().split('\n')
for passphrase in passphrases:
	is_duplicated = False
	check_duplicated = {}
	words = passphrase.split(' ')
	for word in words:
		word = ''.join(sorted(word))
		if word in check_duplicated:
			is_duplicated = True
			break
		else:
			check_duplicated[word] = True
	if is_duplicated is False:
		count += 1

print(count)