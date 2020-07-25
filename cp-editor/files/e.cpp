#include <bits/stdc++.h>
#define dbgv(v) cout<<'>'<< #v <<':';for(auto ii:v)cout<<ii<<' ';cout<<endl;
#define dbg(x) cout<<'>'<< #x <<':'<< x <<endl;
using namespace std;
#define int long long

int x;

int fun(vector<pair<int,int>> A, vector<pair<int,int>> B,vector<int> v){
	
	int ret = 0;
	ret += abs(A[0].first - B[v[0]].first);
	ret += abs(A[0].second - B[v[0]].second);
	
	ret += abs(A[1].first - B[v[1]].first);
	ret += abs(A[1].second - B[v[1]].second);
	
	ret += abs(A[2].first - B[v[2]].first);
	ret += abs(A[2].second - B[v[2]].second);
	
	ret += abs(A[3].first - B[v[3]].first);
	ret += abs(A[3].second - B[v[3]].second);
	
	return ret;

}

void run_case(){
	vector<pair<int,int>> A(4);
	vector<pair<int,int>> B(4);
	for(int i =0;i<4;i++){
		int x,y;
		cin>>x>>y;
		A[i] = {x,y};
	}
	int cx = (A[0].first + A[1].first + A[2].first + A[3].first)/4;
	int cy = (A[0].second + A[1].second + A[2].second + A[3].second)/4;
	
	if((A[0].first + A[1].first + A[2].first + A[3].first)%4 >2) cx++;
	if((A[0].second + A[1].second + A[2].second + A[3].second)%4>2)cy++;
	
	for(int i =0;i<4;i++){
		B[i] = {cx,cy};
	}
	int ans = LLONG_MAX;
	
	vector<int> v = {0,1,2,3};
	do{
		ans = min(ans,fun(A,B,v));
	}while(next_permutation(v.begin(),v.end()));

	cout<<ans<<endl;
	
}

signed main(){
ios_base::sync_with_stdio(false);
cin.tie(0);cout.tie(0);int tc=1;
cin>>tc;
while(tc--)run_case();
return 0;
}