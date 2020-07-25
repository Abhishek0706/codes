vector<int> primes;
void Sieve(int N){
	vector<bool> is_prime(N+1,true);
	primes.clear();
	for (int i=2;i*i<=N;i++) {
		if (is_prime[i]) {
			for (int j=2;j*i<= N;j++) {
				is_prime[i*j]=false;
			}
		}
	}
	for(int i=2;i<=N;i++){
		if(is_prime[i])
			primes.push_back(i);
	}
}
vector<int> spf;
void SPF(int N){
	spf.clear();
	spf = vector<int>(N+1,-1);
	for(auto p : primes){
		for(int j =1;p*j<=N;j++){
			if(spf[p*j]==-1)spf[p*j] = p;
		}
	}
}
