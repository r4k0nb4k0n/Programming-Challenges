import sys

# up, down, left, right, up-left, up-right, down-left, down-right
mv_x = [0, 0, -1, 1, -1, 1, -1, 1]
mv_y = [1, -1, 0, 0, 1, 1, -1, -1]

grid = {}

def pos(x, y):
	return str(x)+", "+str(y)

def look_around_neighbors(x, y):
	sum_of_neighbors = 0
	for i in range(8):
		look_x, look_y = x+mv_x[i], y+mv_y[i]
		look = pos(look_x, look_y)
		if look in grid:
			sum_of_neighbors += grid[look]
	return sum_of_neighbors

def draw_grid(threshold):
	x, y = 0, 0
	n = 1
	grid[pos(x, y)] = n
	dimension = 0
	while True:
		if n>threshold:
			break
		# go right and increase dimension.
		x, y = x+mv_x[3], y+mv_y[3]
		dimension += 1
		n = look_around_neighbors(x, y)
		grid[pos(x, y)] = n
		if n>threshold:
			break
		# go up.
		for i in range(dimension*2-1):
			x, y = x+mv_x[0], y+mv_y[0]
			n = look_around_neighbors(x, y)
			grid[pos(x, y)] = n
			if n>threshold:
				break
		if n>threshold:
				break
		# go left.
		for i in range(dimension*2):
			x, y = x+mv_x[2], y+mv_y[2]
			n = look_around_neighbors(x, y)
			grid[pos(x, y)] = n
			if n>threshold:
				break
		if n>threshold:
				break
		# go down.
		for i in range(dimension*2):
			x, y = x+mv_x[1], y+mv_y[1]
			n = look_around_neighbors(x, y)
			grid[pos(x, y)] = n
			if n>threshold:
				break
		if n>threshold:
				break
		# go right.
		for i in range(dimension*2):
			x, y = x+mv_x[3], y+mv_y[3]
			n = look_around_neighbors(x, y)
			grid[pos(x, y)] = n
			if n>threshold:
				break
		if n>threshold:
				break
	return n
threshold = 0
with open('input.txt', 'r') as f:
	threshold = int(f.readline())
print(threshold)
print(draw_grid(threshold))