class Tree:
	def __init__(self, val):
		self.val = val
		self.left = None
		self.right = None


root = Tree(1)
root.left = Tree(2)
root.right = Tree(3)
root.left.left = Tree(4)
root.left.right = Tree(5)
root.left.right.left = Tree(6)
root.left.right.right = Tree(7)

#let's find the path from root to the required node in this binary tree
path = []
node = root.left.right.right

def findPath(root, node, path):
	#first check if root is None
	if root == None:
		return False

	#if root is not None, then add it to the path
	path.append(root.val)

	#now if we have found the node, then return true
	if(root == node):
		return True

	#as it is a binary tree, we don't know where the required node exists
	#so, we will traverse through the left and right sub trees
	#we will only do this if and only if the left or right nodes exist
	if(findPath(root.left, node, path) or findPath(root.right, node, path)):
		return True

	#if we have come this far, then we can say that none of the above conditions were true
	#so, this node here is either not equal to the node we are looking for
	#or this node does not have any children. The only option we are left with is to go back
	#to the previous nodes. So, we'll pop this node from the path list and backtrack
	path.pop();

	#once we'll pop the element, return False
	return False


findPath(root, node, path)
print(path)