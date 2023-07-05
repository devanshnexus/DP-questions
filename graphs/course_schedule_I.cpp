#include<iostream>
#include<vector>
#include<queue>
using namespace std;
class Solution
{
public:
	vector<int> findOrder(int V, int m, vector<vector<int>> preq){
		vector<int> adj[V];
		for (auto it : preq) {
			adj[it[1]].push_back(it[0]);
		}
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
		vector<int> topo;
		while (!q.empty()) {
			int node = q.front();
			q.pop();
			topo.push_back(node);
			for (auto it : adj[node]) {
				indegree[it]--;
				if (indegree[it] == 0) q.push(it);
			}
		}
		if (topo.size() == V) return topo;
		return {};
	}
};
int main() {
	int N = 4;
	int M = 3;
	vector<vector<int>> preq(3);
	preq[0].push_back(0);
	preq[0].push_back(1);
	preq[1].push_back(1);
	preq[1].push_back(2);
	preq[2].push_back(2);
	preq[2].push_back(3);
	Solution obj;
	vector<int> ans = obj.findOrder(N, M, preq);
	for (auto task : ans) {
		cout << task << " ";
	}
	cout << endl;
	return 0;
}