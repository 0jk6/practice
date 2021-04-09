//Cycle in directed graph
//maintain two visited arrays
//one keeps track of visited nodes
//and the other keeps track of the visited nodes in current recursive call
//once the node visited is true in both the visited arrays then we can say that there is a cycle

void dfs(int node, bool vis[], bool rec[]){
	if(vis[node]==false){
		vis[node] = true;
		rec[node] = true;

		for(auto it : adj[node]){
			if(!vis[it] && dfs(it, vis, rec))
				return true;
			else if(rec[node] == true)
				return true;
		}
	}

	rec[node] = false;
	return false;
}
