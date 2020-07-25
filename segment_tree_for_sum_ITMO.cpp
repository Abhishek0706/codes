// ITMO - segment tree

// completely outside -- return 0;
// completely inside -- return val;
// else -- go deeper

// left child - 2i +1
// right child - 2i +2
// parent - i-1/2

// l--------r-1, r
// |__________|

// x-> current root node in segment tree
// l,r -> our query that we want
// lx,rx -> segment in input vector(a) corresponds to current node x
// l,r,lx,rx <= n == a.size()

// first call st.init(n) to initialise segment tree
// then call st.build(a) to build segment tree using input vector a
// to update value call st.set(index,value)
// to get value of segment call st.sum(left,right)

// IF YOU DONT WANT TO UPDATE, USE PREFIX SUM INSTEAD.

#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct segtree{
	int size;
	vector<ll> sums;
	
	void init(int n){
		size = 1;
		while(size < n)size *= 2;
		sums = vector<ll>(2*size,0LL);
	}
	
	void build(vector<int> &a, int x, int lx, int rx){
		if(rx-lx == 1){
			if(lx < (int)a.size()){
				sums[x] = a[lx];
			}
			return;
		}
		int m = (lx+rx)/2;
		build(a, 2*x+1, lx, m);
		build(a, 2*x+2, m , rx);
		
		sums[x] = sums[2*x + 1] + sums[2*x + 2];
	}
		
	void set(int i, int v,int x, int lx, int rx){
		if(rx-lx ==1){
			sums[x] = v;
			return;
		}
		int m = (lx + rx)/2;
		
		if(i<m){
			set(i, v, 2*x+1, lx, m);
		}else{
			set(i, v ,2*x+2, m, rx);
		}
		sums[x] = sums[2*x+1] + sums[2*x+2];
	}
	
	ll sum(int l, int r, int x, int lx, int rx){
		if(l >= rx || r <= lx) return 0;
		if(lx >= l && rx <= r) return sums[x];
		
		int m = (lx + rx)/2;
		return sum(l,r,2*x+1,lx,m) + sum(l,r,2*x+2,m,rx); 
		
	}
	
	void build(vector<int> &a){
		build(a,0,0,size);
	}
	
	void set(int i, int v){
		set(i,v,0,0,size);
	}
	
	ll sum(int l, int r){
		return sum(l,r,0,0,size);
	}
};


int main(){
	int n,m;
	cin>>n>>m;
	vector<int> a(n); 
	segtree st;
	st.init(n);
	
	for(int i =0;i<n;i++){
		cin>>a[i];
	}
	st.build(a);
	
	while(m--){
		int op;
		cin>>op;
		if(op==1){
			int i ,v;
			cin>>i>>v;
			st.set(i,v);
		}
		else{
			int l ,r;
			cin>>l>>r;
			cout<<st.sum(l,r)<<endl; 
		}
		
	}
	
	return 0;
}
