#include <bits/stdc++.h>
using namespace std;
#define dbgv(v) cout<<'>'<< #v <<':';for(auto ii:v)cout<<ii<<' ';cout<<endl;
#define dbg(x) cout<<'>'<< #x <<':'<< x <<endl;
#define int long long


void run_case(){
	int n;
	cin>>n;
	
	int x = 0;
	int v = 0;
	int j = 1;
	
	while(v<n){
		v+=j;
		j++;
		x++;
	}
	// dbg(v)
	if(v==n){
		cout<<x<<endl;
		return;
	}
	if(v==n+1){
		cout<<x+1<<endl;
		return;
	}
	cout<<x<<endl;
}

signed main(){
ios_base::sync_with_stdio(false);
cin.tie(0);cout.tie(0);int tc=1;
cin>>tc;
while(tc--)run_case();
return 0;
}