int heightOfBinaryTree(TreeNode *root){
	if(root == nullptr)
		return 0;
	//traverse the left subtree
	int lh = heightOfBinaryTree(root->left);
	//traverse the right subtree
	int rh = heightOfBinaryTree(root->right);

	//return the max + 1, we add 1 because we did not count the root node
	return max(lh, rh) + 1;
}