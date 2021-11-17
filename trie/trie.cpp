#include <iostream>

using namespace std;

struct Node{
	//for every single node, there will be 26 references
	Node *links[26];
	bool flag = false;

	//returns true if a reference node exists for a character
	bool containsChar(char ch){
		return (links[ch-'a'] != nullptr);
	}

	//puts a new reference node for a character
	void put(char ch, Node *node){
		links[ch-'a'] = node;
	}

	//gets the reference node of a character
	Node* get(char ch){
		return links[ch-'a'];
	}

	//sets the flag of reference node to true
	//this will tell us that this node is end of a certain word
	void setEnd(){
		flag = true;
	}

	//gets the end flag value
	bool getEnd(){
		return flag;
	}
};

class Trie{
private:
	Node *root;
public:
	//add a constructor
	Trie(){
		root = new Node();
	}
	//we have three functions
	//insert, search, and startswith

	void insert(string s){
		//we will insert a character from string s, only if it's reference node is not present
		Node *node = root;

		for(int i=0; i<s.length(); i++){
			//if the current characater does not have a reference node
			//then we'll create one
			if(!node->containsChar(s[i])){
				node->put(s[i], new Node());
			}

			//now move to the reference node
			node = node->get(s[i]);
		}

		//once we insert all the characters of a string, we should set the flag to true
		node->setEnd();
	}


	bool search(string s){
		Node *node = root;

		for(int i=0; i<s.length(); i++){
			//if the character does not have a reference node, then we can say
			//that there is no string s in the trie
			if(!node->containsChar(s[i])){
				return false;
			}

			//if the character has a reference node, then we'll move on to that reference node
			node = node->get(s[i]);
		}

		//once we complete the searching, we should check whether this
		//last node has a flag = true, that will tell us that the word is complete
		if(!node->getEnd())
			return false;

		return true;
	}

	bool startswith(string s){
		//similar to search function, but we don't need to check for the end reference node's flag
		Node *node = root;

		for(int i=0; i<s.length(); i++){
			if(!node->containsChar(s[i])){
				return false;
			}

			node = node->get(s[i]);
		}

		return true;
	}

};


int main(){

	Trie t;
	t.insert("hello");
	t.insert("world");

	cout << t.search("hello") << "\n"; //should return true
	
	cout << t.search("world") << "\n"; //should return true
	
	cout << t.startswith("hel") << "\n"; //should return true
	
	cout << t.startswith("worl7") << "\n"; //should return false

	return 0;
}