from anytree import Node, RenderTree, PreOrderIter
from sys import getsizeof

nodes = []
weight = {}

def is_exist(name):
	for idx, node in enumerate(nodes):
		if node.name == name:
			return idx
	return -1

# parsing
with open('input.txt', 'r') as f:
	lines = f.read().split('\n')
	lines.sort(key=len)
	for line in lines:
		line = line.lstrip().rstrip()
		weight[line[0:line.find('(')-1]] = int(line[line.find('(')+1:line.find(')')])
		if(line.find('->') > -1):
			token = line.split('-> ')
			token[0] = token[0].lstrip().rstrip()[:token[0].find(' ')]
			token[1] = token[1].split(', ')
			# Avoid duplicating...
			idxOfParent = is_exist(token[0])
			if idxOfParent == -1:
				nodes.append(Node(token[0]))
				idxOfParent = len(nodes)-1
			for item in token[1]:
				# Avoid duplicating...
				idxOfChild = is_exist(item)
				if idxOfChild == -1:
					nodes.append(Node(item, parent=nodes[idxOfParent]))
				else:
					nodes[idxOfChild].parent = nodes[idxOfParent]
				
		else:
			token = line.split(' ')
			# Avoid duplicating...
			idxOfNode = is_exist(token[0])
			if idxOfNode == -1:
				nodes.append(Node(token[0]))


# Sort nodes by the number of descendants.
# nodes[0] will be the bottom node of the tower.
nodes.sort(key=lambda x:len(x.descendants), reverse=True)

def is_balanced(node):
	stacked_sum = weight[node.name]
	des = [is_balanced(child) for child in node.children]
	if len(des) != 0:
		print(node.name, des, node.children)
	if len(set(des)) <= 2:
		stacked_sum = stacked_sum + sum(des)
	else:
		print(node.name, des)
		print(node.children)
	return stacked_sum

is_balanced(nodes[0])
#for node in PreOrderIter(nodes[0]):
#	node.name = node.name + ' (' + str(weight[node.name]) + ')'
	
#for pre, fill, node in RenderTree(nodes[0]):
#	print("%s%s" % (pre, node.name))
