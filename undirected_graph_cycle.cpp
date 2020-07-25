bool detect_cycle(int root, vector<vector<int>> &node ,vector<int> &parent, vector<bool> &visited){
    if(visited[root]) return 1;
    visited[root] = 1;
    for(auto i : node[root]){
        if(i!=parent[root]){
            parent[i] = root;
            if(detect_cycle(i,node,parent,visited))return 1;
        }
    }
    return 0;
}

int Solution::solve(int n, vector<vector<int> > &E) {
    vector<vector<int> > node(n+1);
    vector<int> parent(n+1,0);
    vector<bool> visited(n+1,0);
    for( auto i : E){
        int x = i[0];
        int y = i[1];
        node[x].push_back(y);
        node[y].push_back(x);
    }
    for(int i =1;i<=n;i++){
        if(!visited[i] && detect_cycle(i,node,parent,visited))return 1;
    }
    return 0;
}