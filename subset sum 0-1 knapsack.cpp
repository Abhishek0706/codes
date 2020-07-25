// v is vector
// x is target sum
vector<vector<bool>> dp(v.size()+1,vector<bool>(x+1,false));
for(int i =0;i<=v.size();i++){
	dp[i][0] = 1;
}
for(int i =1;i<=v.size();i++){
	for(int j =1;j<=x;j++){
		if(v[i-1]>j)dp[i][j]=dp[i-1][j];
		else{
			dp[i][j] = dp[i-1][j] || dp[i-1][j-v[i-1]];
		}
	}
}
