bool hasCycle(int V, vector<int> adj[]){
	vector<int> vis(V, 0);

	for(int i=0; i<V; i++){
		if(!vis[i]){
			if(helper(i, vis, adj))
				return true;
		}
	}
	return false;
}


bool helper(int s, vector<int> &vis, vector<int> adj[]){
	queue<pair<int, int>> q; //push, current node and parent

	q.push({s, -1}); //as there is no parent for the current node

	vis[s] = 1;

	while(!q.empty()){
		int node = q.front().first;
		int parent = q.front().second;

		q.pop();

		for(auto it : adj[node]){
			if(!vis[it]){
				vis[it] = 1;
				q.push({it, node}); //current node and its parent
			}
			else if(it != parent)
				return true;
		}
	}
	return false;
}