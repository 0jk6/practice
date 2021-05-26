#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct bst{
	int data;
	struct bst *right;
	struct bst *left;
};

struct bst *createNewNode(int data){
	struct bst *newnode;
	newnode = (struct bst*)malloc(sizeof(struct bst));
	newnode->data = data;
	newnode->right = NULL;
	newnode->left = NULL;
	return newnode;
}

struct bst *insert(struct bst *root, int data){
	if(root==NULL){
		root = createNewNode(data);
		return root;
	}
	if(data<=root->data){
		root->left = insert(root->left,data);
	}
	else{
		root->right = insert(root->right,data);
	}
	return root;
}

int min(struct bst *root){
	while(root->left!=NULL){
		root = root->left;
	}
	return root->val;
}

struct bst *delete(struct bst *root, int data){
	if(root == NULL)
		return root;
	else if(data < root->data)
		//search the left sub tree
		root->left = delete(root->left, data);
	else if(data > root->data)
		//search the right sub tree
		root->right = delete(root->right, data);
	else{
		if(root->left == NULL){
			return root->right;
		}
		else if(root->right == NULL)
			return root->left;
		}
		//Case 3: Two childs
		else{
			root->val = min(root->right);
			root->right = delet(root->right, root->val);
		}
	}
	return root;
}

bool search(struct bst *root, int data){
	if(root==NULL){
		return false;
	}
	else if(root->data == data){
		return true;
	}
	else if(data <= root->data){
		return search(root->left, data);
	}
	else{
		return search(root->right, data);
	}
}

int preOrder(struct bst *root){
	//root, left, right
	if(root==NULL)
		return 0;

	printf("%d ",root->data);
	if(root->left != NULL)
		preOrder(root->left);
	if(root->right != NULL)
		preOrder(root->right);

}

int inOrder(struct bst *root){
	//left, root, right
	if(root == NULL)
		return 0;
	if(root->left != NULL)
		inOrder(root->left);
	printf("%d ",root->data);
	if(root->right != NULL)
		inOrder(root->right);
}

int postOrder(struct bst *root){
	//left, right, root
	if(root == NULL)
		return 0;
	if(root->left != NULL)
		postOrder(root->left);
	if(root->right != NULL)
		postOrder(root->right);

	printf("%d ",root->data);
}

int main(){
	struct bst *root; // this is not a node, its a pointer pointing to root node
	root = NULL;
	int d;
	printf("Enter 111 to exit!\n");
	while(true){
		printf("Enter data: ");
		scanf("%d",&d);
		if(d==111)
			break;
		else{
			if(root == NULL)
				root = insert(root,d);
			else
				insert(root,d);
		}
	}

	printf("\n----------Pre Order----------\n");
	preOrder(root);

	printf("\n----------In Order----------\n");
	inOrder(root);

	printf("\n----------Post Order----------\n");
	postOrder(root);

	delete(root,5);
	printf("\n----------After deletion-------------\n");
	inOrder(root);
	return 0;
}
