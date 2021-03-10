#include <iostream>
#include <vector>

using namespace std;

void addEdge(vector<int> graph[], int s, int d){
  //This is for undirected graph
  graph[s].push_back(d);
  graph[d].push_back(s);
}

void printGraph(vector<int> graph[], int v){
  for(int i=0; i<v; i++){
    cout << i;
    for(int j=0; j<graph[i].size(); j++){
      cout << "->" << graph[i][j];
    }
    cout << "\n";
  }
}

void addEdgeWeights(vector<pair<int,int>> graph[], int s, int d, int w){
  //For undirected graph
  graph[s].push_back({d,w});
  graph[d].push_back({s,d});
}

int main(){
  //s and d are start and end vertex of edge
  //(s,d) vertex
  int v, e, s, d;
  cout << "Enter number of vertices: ";
  cin >> v;
  cout << "Enter number of edges: ";
  cin >> e;
  //declare the adjacency list
  vector<int> graph[v];
  
  //call the addEdge() function e number of times
  for(int i=0; i<e; i++){
    cout << "Enter start and end vertex of edge: ";
    cin >> s;
    cin >> d;
    addEdge(graph,s,d);
  }
  printGraph(graph,v);
  return 0;
}
