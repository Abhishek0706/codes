vector<int> calcZ(string s){
    int n = s.size();
    vector<int> Z(n,0);
    for(int i=1,x=0,y=0;i<n;i++){
        if(i<=y) Z[i]=min(y-i,Z[i-x]); //taking values using z box
        while(i+Z[i]<n && s[i+Z[i]]==s[Z[i]]) Z[i]++; //native calculation
        if(y<=i+Z[i]) x=i,y=i+Z[i]; //updating z-box based on current result
    }
    return Z;
}
