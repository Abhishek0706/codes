// wrost case order of root(n)
vector<pair<int,int>> prime_factorize(int n){
	vector<pair<int,int>> ret;
	for(int i =2;i*i<=n;i++){
		if(n%i==0){
			ret.push_back({i,0});
			while(n%i==0){
				n/=i;
				ret.back().second++;
			}
		}
	}
	if(n>1){
		ret.push_back({n,1});
	}
	return ret;
}
