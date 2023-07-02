#include<iostream>
#include<vector>
#include<queue>
using namespace std;
class Solution {
  private: 
    bool dfs(int node, int parent, int vis[], vector<int> adj[]) {
        vis[node] = 1; 
        for(auto it: adj[node]) {
            if(!vis[it]) {
                if(dfs(it, node, vis, adj) == true) 
                    return true; 
            }
            else if(it != parent) return true; 
        }
        return false; 
    }
  public:
    bool isCycle(int V, vector<int> adj[]) {
       int vis[V] = {0}; 
       for(int i = 0;i<V;i++) {
           if(!vis[i]) {//check for connected components
               if(dfs(i, -1, vis, adj) == true) return true; 
           }
       }
       return false; 
    }
};

int main() {
    vector<int> adj[4] = {{}, {2}, {1, 3}, {2}};
    Solution obj;
    bool ans = obj.isCycle(4, adj);
    if (ans)
        cout << "1\n";
    else
        cout << "0\n";
    return 0;
}