#include <iostream>
#include <queue>

using namespace std;

struct bst{
	int data;
	struct bst *right;
	struct bst *left;
};

struct bst *root;

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
	}
	else if(data<=root->data){
		root->left = insert(root->left,data);
	}
	else{
		root->right = insert(root->right,data);
	}
	return root;
}

//bfs function using queue
void bfs(struct bst *root){
	if(root==NULL)
		return;
	queue<struct bst*> q;
	q.push(root);
	while(!q.empty()){
		struct bst *current = q.front();
		cout << current->data << " ";
		if(current->left!=NULL)
			q.push(current->left);
		if(current->right!=NULL)
			q.push(current->right);
		q.pop();
	}
}

int main(){
	root = NULL;
	while(true){
		int x;
		cout << "Enter data:";
		cin >> x;
		if(x==111)
			break;
		if(root==NULL)
			root = insert(root,x);
		else
			insert(root,x);
		cout << "\n";
	}
	cout << "BFS: " << "\n";
	bfs(root);
	return 0;
}
