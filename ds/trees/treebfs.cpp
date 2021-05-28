#include <iostream>
#include <queue>
#include <stack>

namespace tree {
    struct Node{
        int val;
        Node *left;
        Node *right;

        Node(int data){
            val = data;
            left = nullptr;
            right = nullptr;
        }
    };

    void bfs(Node *root){
        std::cout << "BFS Traversal of the tree\n";
        std::queue<Node*> q;
        q.push(root);
        int len;
        Node *temp = nullptr;

        while(!q.empty()){
            len = q.size();
            for(int i=0; i<len; i++){
                temp = q.front();
                q.pop();
                std::cout << temp->val << " ";

                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);
            }
        }
        std::cout << "\n";
    }

    //inorder dfs
    void dfs(Node *root){
        std::cout << "DFS Traversal of the tree (inorder iterative)\n";
        std::stack<Node*> st;
        
        while(!st.empty() || root != nullptr){
            //push all the left nodes
            while(root != nullptr){
                st.push(root);
                root = root->left;
            }

            root = st.top();
            st.pop();

            std::cout << root->val << " ";

            root = root->right;
        }
    }
}


int main(){
    tree::Node *root = new tree::Node(1);
    root->left = new tree::Node(-1);
    root->right = new tree::Node(2);
    root->left->left = new tree::Node(-3);
    root->left->right = new tree::Node(-2);
    root->right->left = new tree::Node(2);
    root->right->right = new tree::Node(3);

    tree::bfs(root);
    tree::dfs(root);
}