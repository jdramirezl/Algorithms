#include <bits/stdc++.h>

using namespace std;

#define vvi vector<vector<int>> 

void dfs(vvi &graph, vector<bool> &visited, int curr_node){
    
    if(visited[curr_node]) {
        for(int i=0; i<visited.size();++i){
            cout << visited[i] << " ";
        }
        cout << " traversal dead-end " <<endl;
        return;
    }

    cout << "Current Node: " << curr_node << endl;
    visited[curr_node] = true;

    for(int i=0; i<graph[curr_node].size(); ++i){
        int next = graph[curr_node][i];
        dfs(graph, visited, next);
    }
}


int main(){
    int n_of_nodes, n_of_edges, start, end;

    //Number of nodes and edges
    cin >> n_of_nodes >> n_of_edges;
    vvi graph(n_of_nodes, vector<int>()); 

    //Fill visited array
    vector<bool> visited(n_of_nodes, false);

    //Fill graph
    for(int i=0; i<n_of_edges; ++i){
        cin >> start >> end;
        graph[start - 1].push_back(end - 1);
    }

    for(int i=0; i<n_of_nodes;++i) dfs(graph, visited, i);
}