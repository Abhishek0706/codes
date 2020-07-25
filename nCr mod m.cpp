const int M = 998244353;
const int N = 300001;
vector<int> fact(N,0);
vector<int> rfact(N,0);

int pow_mod(int a, int n){
	if(n==0) return 1;
	if(n%2==0){
		int temp = pow_mod(a,n/2);
		return (temp*temp)%M;
	}
	return (a * pow_mod(a,n-1))%M;
}

void fact_rfact_calc(){
	fact[0]=1;
	rfact[0]=1;
	for(int i=1;i<N;i++){
		fact[i]=(i*fact[i-1])%M;
		rfact[i]=(rfact[i-1]*pow_mod(i,M-2))%M;
	}
}

int choose(int n, int r){
	if (r < 0 || r > n) return 0;
	int temp = fact[n];
	temp *= rfact[r]; temp %= M;
	temp *= rfact[n-r]; temp %= M;
	return temp;
}

// based on fermet's little theorem 
// a^p mod p = a mod p
// a^(p-2) mod p = a^-1 mod p
// nCr%m = (fact[n]* modIverse(fact[r]) % m * modIverse(fact[n-r]) % m) % m;
// modInverse(fact[i])%m = modeInverse(fact[i-1] * i)%m
// = (rfact[i-1] * modInverse(i) )%m
// for calculating modInverse(i) we are using the above approach


//call fact_rfact_calc() for precalculation

modInverse(fact i) = modInverse(i * fact i-1) = (modInverse(i) * modInverse(face i-1)) %m
rfact(i) = modInverse(i) * rfact(i-1) %m
