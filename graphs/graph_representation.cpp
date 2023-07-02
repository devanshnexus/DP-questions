#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n, m;
    cin >> n >> m;
    int adj[n+1][n+1];
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        adj[u][v] = 1;
        adj[v][u] = 1;
    }
    // using vectors
    vector<int> adj2[n+1];
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        adj2[u].push_back(v);
        adj2[v].push_back(u);
    }
    // for directed graph
    vector<int> adj3[n+1];
    for(int i = 0; i < m; i++){
        int u, v;
        // u —> v
        cin >> u >> v;
        adj3[u].push_back(v);
    }
    return 0;
}