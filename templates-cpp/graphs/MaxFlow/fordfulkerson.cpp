#include <iostream>
#include <limits.h>
#include <queue>
#include <string.h>

using namespace std;

// Number of vertices in given graph
#define V 6
/*
 * Returns true if there is a path from source 's' to sink 't' in residual graph.
 * Also fills parent[] to store the path
 */
bool bfs(int rGraph[V][V] int s, int t, int parent[]){

   // Create a visited array and mark all vertices as not visited 
    bool visited[V];
    memset(visited, 0, sizeof(visited));
    // Create a queue, enqueue source vertex and mark source vertex as visited
    queue<int> q;
    q.push(s);
    visited[s] = true;
    parent[s] = -1;

    // Standard BFS Loop
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int v = 0; v < V; v++){
            if(visited[v] == false && rGraph[u][v] > 0){
               // If we find a connection to the sink node,
               // then there is not point in BFS anymore 
               // We just have to set its parennt and can return true
               if(v == t){
                    parent[v] = u;
                    return true;
               }
               q.push(v);
               parent[v] = u;
               visited[v] = true;
            }
        }
    }
    // We didn't reach sink in BFS starting from source, so return false
    return false;
}

int main(){
    return 0;
}
