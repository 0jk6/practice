//Topological sorting is only possible in Directed Acyclic Graph

stack<int> st;

bool dfs(int node, vector<int> &vis){
	vis[node] = true;

	for(auto it: adj[node]){
		if(!vis[it])
			dfs(it)
	}

	st.push(node);
}

//pop the elements of the stack and you'll get the topological sort