int knapsack(vector<int> &val, vector<int> &wt, int cap) {
    vector<vector<int> > dp(val.size()+1,vector<int>(cap+1,0));
    
    for(int i =1;i<=val.size();i++){
        for(int j = 1;j<=cap;j++){
            if(j<wt[i-1]){
                dp[i][j] = dp[i-1][j];
            }
            else{
                dp[i][j] = max(dp[i-1][j],dp[i-1][j-wt[i-1]]+ val[i-1]);
            }
        }
    }
    
    return dp[val.size()][cap];
}
