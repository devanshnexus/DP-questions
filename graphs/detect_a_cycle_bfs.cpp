#include<iostream>
#include<vector>
#include<queue>
using namespace std;
class Solution {
  private: 
    bool detect(int src, vector<int> adj[], int vis[]) {
        vis[src] = 1; 
        queue<pair<int,int>> q; 
        q.push({src, -1}); 
        while(!q.empty()) {
            int node = q.front().first; 
            int parent = q.front().second; 
            q.pop(); 
            for(auto it: adj[node]) {
                if(!vis[it]) {
                    vis[it] = 1; 
                    q.push({it, node}); 
                }
                else if(parent != it) {
                    return true; 
                }
            }
        }
        return false; 
  }
  public:
    bool isCycle(int V, vector<int> adj[]) { 
        int vis[V] = {0};
        for(int i = 0;i<V;i++) {
            if(!vis[i]) {//check for connected components
                if(detect(i, adj, vis)) return true; 
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