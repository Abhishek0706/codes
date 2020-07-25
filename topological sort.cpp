vector<int> ord;
vector<bool> visited(200005,false);
 
void dfs(int i){
	visited[i] = true;
	for(auto it : node[i]){
		if(!visited[it]) dfs(it);
	}
	ord.push_back(i);
}


	for(int i =1;i<=n;i++){
		if(!visited[i])dfs(i);
	}
	reverse(ord.begin(),ord.end());