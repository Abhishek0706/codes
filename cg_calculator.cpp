#include <bits/stdc++.h>
using namespace std;
#define dbgv(v) cout<<'>'<< #v <<':';for(auto ii:v)cout<<ii<<' ';cout<<endl;
#define dbg(x) cout<<'>'<< #x <<':'<< x <<endl;

signed main(){
	map<string,int>mp;
	mp["A"]=10;
	mp["B+"]=9;
	mp["B"] = 8;
	mp["C+"]=7; 
	vector<int> grade,credit;
	int tot = 0;
	int totc = 0;
	while(true){
		int c;
		string g;
		cin>>g>>c;
		if(c==-1)break;
		if(g!="S"){
			totc+= c;
			tot += c * mp[g];
		}
	}
	cout<<(double)tot/(double)totc;
	return 0;
}

/*
B 3
C+ 2
B 4
B+ 2
A 2
B 4
B+ 4

C+ 4
B 4
B 4
C+ 4
C+ 4
C+ 4

B 4
A 2
B 4
C+ 4
B 3
C+ 4

C+ 4
B 4
B+ 3
B 4
S 2
C+ 4

S 4
B 4
B+ 4
B+ 4
A 2
B+ 3



A -1
*/
