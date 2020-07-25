int min(int x ,int y, int z){
    return min(x,min(y,z));
}

int editDistance(string str1, string str2) {
    int m = str1.size();
    int n = str2.size();
    vector<vector<int>> dp (m+1,vector<int>(n+1,0));
  
    for (int i = 0; i <= m; i++) { 
        for (int j = 0; j <= n; j++) { 
            if (i == 0) 
                dp[i][j] = j;// insert rem element of s2 into s1
            else if (j == 0) 
                dp[i][j] = i; //delete remaining element of s1
  
            else if (str1[i - 1] == str2[j - 1]) 
                dp[i][j] = dp[i - 1][j - 1]; // no op
            else
                dp[i][j] = 1 + min(dp[i][j - 1],//insert
                                   dp[i - 1][j],//delete
                                   dp[i - 1][j - 1]);//replace
        } 
    } 
  
    return dp[m][n]; 
}
