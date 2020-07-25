vector<int> getLps(string s){
	int n = s.size();
	vector<int> lps(n,0);
	int i = 1,j=0;
	while(i<n){
		if(s[i]==s[j]){
			lps[i] = j+1;
			i++;
			j++;
		}
		else{
			if(j==0){
				lps[i] = 0;
				i++;
			}else{
				j = lps[j-1];
			}
		}
	}
	return lps;
}