#include<iostream>
#include<vector>
#include<queue>
using namespace std;
class Solution {
public:
	bool isCyclic(int V, vector<int> adj[]){
		int indegree[V] = {0};
		for (int i = 0; i < V; i++) {
			for (auto it : adj[i]) {
				indegree[it]++;
			}
		}
		queue<int> q;
		for (int i = 0; i < V; i++) {
			if (indegree[i] == 0) {
				q.push(i);
			}
		}
		int count = 0;
		while (!q.empty()) {
			int node = q.front();
			q.pop();
            count++;
			for (auto it : adj[node]) {
				indegree[it]--;
				if (indegree[it] == 0) q.push(it);
			}
		}
		if(count == V ) return false;
        return true;
	}
};
int main() {
	vector<int> adj[6] = {{}, {}, {3}, {1}, {0, 1}, {0, 2}};
	int V = 6;
	Solution obj;
	bool ans = obj.isCyclic(V, adj);
	cout<< ans;
	cout << endl;
	return 0;
}