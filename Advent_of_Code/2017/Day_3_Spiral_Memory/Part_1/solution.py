import sys

# up, down, left, right
mv_x = [0, 0, -1, 1]
mv_y = [1, -1, 0, 0]

def distance_to_access(pos):
	manhatan_distance = 0
	x, y = 0, 0
	n = 1
	dimension = 0
	while True:
		if n>=pos:
			break
		# go right and increase dimension.
		x, y = x+mv_x[3], y+mv_y[3]
		dimension += 1
		n += 1
		if n>=pos:
			break
		# go up.
		for i in range(dimension*2-1):
			x, y = x+mv_x[0], y+mv_y[0]
			n += 1
			if n>=pos:
				break
		if n>=pos:
				break
		# go left.
		for i in range(dimension*2):
			x, y = x+mv_x[2], y+mv_y[2]
			n += 1
			if n>=pos:
				break
		if n>=pos:
				break
		# go down.
		for i in range(dimension*2):
			x, y = x+mv_x[1], y+mv_y[1]
			n += 1
			if n>=pos:
				break
		if n>=pos:
				break
		# go right.
		for i in range(dimension*2):
			x, y = x+mv_x[3], y+mv_y[3]
			n += 1
			if n>=pos:
				break
		if n>=pos:
				break
	print(str(x) + ", " + str(y))
	manhatan_distance = abs(x) + abs(y)
	return manhatan_distance
pos = 0
with open('input.txt', 'r') as f:
	pos = int(f.readline())
print(pos)
print(distance_to_access(pos))