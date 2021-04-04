graph = {
  'A' : ['B','C'],
  'B' : ['D', 'E'],
  'C' : ['F'],
  'D' : [],
  'E' : ['F'],
  'F' : []
}

visited = [] # List to keep track of visited nodes.
queue = []

def bfs(graph, visited, node):

	#we have visited the first node, so add it to the visited list
	visited.append(node)
	#we need to visit other nodes which are connected to the current node
	#so we push it into the queue
	queue.append(node)

	#we'll now process the nodes inside our queue
	while queue:
		#pop an element in the queue
		s = queue.pop(0)

		#print the element
		print(s, end=" ")

		#now visit the connected nodes and append them like we did before into queue and visted lists
		for i in graph[s]:
			if i not in visited:
				visited.append(i)
				queue.append(i)


bfs(graph, visited, 'A')