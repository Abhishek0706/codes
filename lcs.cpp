// length of longest common subsequence
int lcs(string A, string B) {
    int n ,m;
    n = A.size();
    m = B.size();
    vector<vector<int>>dp(n+1,vector<int>(m+1,0));
    for(int i =1;i<=n;i++){
        for(int j = 1;j<=m;j++){
            if(A[i-1]==B[j-1])dp[i][j] = 1 + dp[i-1][j-1];
            else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
        }
    }
    return dp[n][m];
}


// length of longest common substring
int lcs(string A, string B) {
    int n ,m;
    n = A.size();
    m = B.size();
    int ans = 0;
    vector<vector<int>>dp(n+1,vector<int>(m+1,0));
    for(int i =1;i<=n;i++){
        for(int j = 1;j<=m;j++){
            if(A[i-1]==B[j-1])dp[i][j] = 1 + dp[i-1][j-1];
            else dp[i][j] =0;
            ans = max(ans,dp[i][j]);
        }
    }
    return ans;
}
