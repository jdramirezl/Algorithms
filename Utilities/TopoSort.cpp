#include <bits/stdc++.h>

using namespace std;

#define vvi vector<vector<int>>

void util(vvi graph, stack<int> &stack, vector<bool> visited, int node){
    visited[node] = true;

    for(int i=0; i<graph[node].size(); ++i){
        int curr_node = graph[node][i];
        if(visited[curr_node]) continue;
        util(graph, stack, visited, curr_node);
    }

    stack.push(node);
}

void topo_sort(vvi graph, vector<bool> visited, int n_of_nodes, int n_of_edges){
    stack<int> sorted_graph;

    for(int i=0; i< n_of_nodes; ++i){
        if(visited[i]) continue;
        util(graph, sorted_graph, visited, i);
    }

    while (!sorted_graph.empty()) {
        cout << sorted_graph.top() << " ";
        sorted_graph.pop();
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
        graph[from].push_back(to);
    }

    topo_sort(graph, visited, n_of_nodes, n_of_edges);
}