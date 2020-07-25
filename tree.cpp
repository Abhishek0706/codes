#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("input.txt", "r", stdin);
	// number of nodes
	int n;
	cin >> n;
	vector<vector<int>> node(n + 1);
	vector<int> parent(n + 1, 0);
	vector<int> height(n + 1, 0);

	// connecting all nodes
	for (int i = 0; i < n - 1 ; i++) {
		int x, y;
		cin >> x >> y;
		node[x].push_back(y);
		node[y].push_back(x);
	}

	// using queue for bfs
	queue<int> qu;

	//root at node 1
	int root = 1;
	qu.push(root);
	height[root] = 1;
	parent[root] = 0;

	// bfs transversal
	while (!qu.empty()) {
		int f = qu.front();
		qu.pop();
		int h = height[f] + 1;
		for (auto i : node[f]) {
			if (i != parent[f]) {
				parent[i] = f;
				height[i] = h;
				qu.push(i);
			}
		}
	}
	//here we get all the heights and parents
	//most of the questions can be solved using height and parent


	//printing BFS of the given tree with root node 1
	cout << "BFS : ";
	queue<int> bfs;
	bfs.push(root);
	while (!bfs.empty()) {
		int f = bfs.front();
		bfs.pop();
		cout << f << " ";
		for (auto i : node[f]) {
			if (i != parent[f])
				bfs.push(i);
		}
	} cout << endl;

	//printing DFS of the given tree
	cout << "DFS : ";
	stack<int> dfs;
	dfs.push(1);
	while (!dfs.empty()) {
		int f = dfs.top();
		dfs.pop();
		cout << f << " ";
		for (auto i : node[f]) {
			if (i != parent[f]) {
				dfs.push(i);
			}
		}
	} cout << endl;

	// get path between the node u and v
	//u = 3 and v = 5 in this example
	int u, v;
	cin >> u >> v;
	vector<int> path, path2;
	while (height[u] > height[v]) {
		path.push_back(u);
		u = parent[u];
	}
	while (height[v] > height[u]) {
		path2.push_back(v);
		v = parent[v];
	}
	while (u != v) {
		path.push_back(u);
		path2.push_back(v);
		u = parent[u];
		v = parent[v];
	}
	path.push_back(u);
	reverse(path2.begin(), path2.end());
	path.insert(path.end(), path2.begin(), path2.end());

	// here we get all values in their path
	cout<<"Path : ";
	for (auto i : path)cout << i << " ";
	cout << endl;

	return 0;
}

//CREATED BY ABHISHEK PATIL
