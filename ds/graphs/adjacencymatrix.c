#include <stdio.h>
#include <string.h>

int adjMatrix(){
	int n;
	printf("Enter number of edges: ");
	scanf("%d",&n);
	int adj[n][n];
	int v, e;
	memset(adj,0,sizeof(int)*n*n);
	
	for(int i=0; i<n; i++){
		printf("Enter V,E: ");
		scanf("%d %d",&v,&e);
		adj[v-1][e-1] = 1;
	}

	for(int i=0; i<n-1; i++){
		for(int j=0; j<n-1; j++){
			printf("%d ",adj[i][j]);
		}
		printf("\n");
	}
}

int adjMatrixWeights(){
	int n;
	printf("Enter number of edges: ");
	scanf("%d",&n);
	int adj[n][n];
	int v, e, w;
	memset(adj,0,sizeof(int)*n*n);
	
	for(int i=0; i<n; i++){
		printf("Enter V,E,W: ");
		scanf("%d %d %d",&v,&e,&w);
		adj[v-1][e-1] = w;
	}

	for(int i=0; i<n-1; i++){
		for(int j=0; j<n-1; j++){
			printf("%d ",adj[i][j]);
		}
		printf("\n");
	}
}

int main(){
	//adjMatrix();
	adjMatrixWeights();
	return 0;
}
