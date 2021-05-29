bool isBipartite(int V, vector<int>adj[]){
    //0 is one color and 1 is the other color
    //initialize visited array with -1
    vector<int> vis(V, -1);

    //traverse
    for(int i=0; i<V; i++){
    	if(vis[i] == -1){
    		if(bfs(i, vis, adj)==false)
    			return false;
    	}
    }

    return true;
}

bool bfs(int s, vector<int> &vis, vector<int> adj[]){
	queue<int> q;
	q.push(s);
	vis[s] = 1; //initialize the coloring with 1

	while(!q.empty){
		int node = q.front();
		q.pop();

		//traverse the adjacency list for the node
		for(auto it : adj[node]){
			//if it was not visited array
			if(vis[it] == -1){
				//color it opposite to it's previous node
				if(vis[node] == 1)
					vis[it] = 0;
				else
					vis[it] = 1;
				q.push(it);
			}
			else{
				//if it was in visited array
				//and the colors of current node and it's previous node are same
				//then return false 
				if(vis[it] == vis[node])
					return false;
			}
		}
	}
	return true;
}