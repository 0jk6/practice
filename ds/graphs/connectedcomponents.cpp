//connected components in graph

void dfs(int node){
	vis[node] = true;

	for(auto it : adj[node]){
		if(!vis[it])
			dfs(it);
	}
}

int main(){
	for(int i=1; i<=N; i++){
		if(!vis[i]){
			count++;
			dfs(i);
		}
	}
}