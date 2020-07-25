//recursive dfs without stack
bool detect_cycle(int root,vector<vector<int>> &node,vector<bool> &visited,vector<bool> &curr){
    if(curr[root]) return 1;
    visited[root] = 1;
    curr[root] = 1;
    for(auto i : node[root]){
            if(detect_cycle(i,node,visited,curr)){
                curr[root] = 0;
                return 1;
                
            }
    }
    curr[root] = 0;
    return 0;
}

int Solution::solve(int n, vector<vector<int> > &E) {
    vector<vector<int> > node(n+1);
    vector<bool> visited(n+1,0);
    vector<bool> curr(n+1,0);
    for(auto i : E){
        node[i[0]].push_back(i[1]);
    }
    for(int i =1;i<=n;i++){
        if(!visited[i] && detect_cycle(i,node,visited,curr))return 1;
    }
    return 0;
}