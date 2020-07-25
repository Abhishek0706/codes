int kadan(vector<int> v){
    int ans = INT_MIN;
    int curr = 0;
    for(int i =0;i<n;i++){
        curr = max(curr + v[i] , v[i]);
        ans = max(ans,curr);
    }
    return ans;
    // if empty array is allowed then 
    // return max(ans,0);
}
