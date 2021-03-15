#include <bits/stdc++.h>
using namespace std;

#define vvi vector<vector<int>>

void bfs(vvi graph, vector<bool> visited, int n_of_nodes, int n_of_edges){
    int curr_node = graph[0][0];
    queue<int> values;
    values.push(curr_node);
    visited[curr_node] = true;

    while(!values.empty()){
        int curr_node = values.front();
        values.pop();

        for(int i = 0; i < graph[curr_node]; ++i){
            int local_node = graph[curr_node][i];
            if(visited[local_node]) continue;
            //Do something
            visited[local_node] = true;
            values.push(local_node);
        }
    }
}

int main(){
    int n_of_nodes, n_of_edges, from, to;

    //Number of nodes and edges
    cin >> n_of_nodes >> n_of_edges;
    vvi graph(n_of_nodes, vector<int>()); 

    //Fill visited array
    vector<bool> visited(n_of_nodes, false);

    //Fill graph
    for(int i=0; i<n_of_edges; ++i){
        cin >> from >> to;
        graph[from - 1].push_back(to - 1);
    }

    bfs(graph);
}