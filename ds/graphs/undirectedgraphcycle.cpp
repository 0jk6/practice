//Cycle detection in Undirected graph 
//Time complexity O(N)
//Space complexity O(N)
//including recursion O(N+N)

bool dfs(int node, vector<int> &vis, int parent){
	vis[node] = true;

	for(auto it: adj[node]){
		if(!vis[it]){
			if(dfs(it, vis, node))
				return true;
		}
		else if(it != parent){
			return true;
		}
	}

	return false;
}