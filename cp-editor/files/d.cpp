#include <bits/stdc++.h>
#define dbgv(v) cout<<'>'<< #v <<':';for(auto ii:v)cout<<ii<<' ';cout<<endl;
#define dbg(x) cout<<'>'<< #x <<':'<< x <<endl;
using namespace std;
#define int long long

bool is_sorted(vector<int> & v){
	for(int i=0;i<(int)v.size()-1;i++){
		if(v[i]>v[i+1])return 0;
	}
	return 1;
}

int getp(vector<int> &v, int x){
	for(int i =0;i<(int)v.size();i++){
		if(v[i]>x)
			return i;
	}
	return -1;
}

void run_case(){
	int n,x;
	cin>>n>>x;
	vector<int> a(n);
	for( auto &i : a)cin>>i;
	if(is_sorted(a)){
		cout<<0<<endl;
		return;
	}
	int cnt = 0;
	while(true){
		int p = getp(a,x);
		if(p==-1){
			cout<<p<<endl;
			return;
		}
		swap(a[p],x);
		cnt++;
		if(is_sorted(a)){
			cout<<cnt<<endl;
			return;
		}
	}
}

signed main(){
ios_base::sync_with_stdio(false);
cin.tie(0);cout.tie(0);int tc=1;
cin>>tc;
while(tc--)run_case();
return 0;
}