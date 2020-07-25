#include <bits/stdc++.h>
using namespace std;

struct fentree{
	int size;
	vector<int> val;
	
	void init(int n){
		size = n+1;
		val = vector<int>(n+1,0);
	}
	
	int get(int index){
		index ++;
		int sum = 0;
		while(index > 0){
			sum += val[index];
			index -= index & (-index);
		}
		return sum;
	}
	
	void add(int index, int v){
		index ++;
		while(index < size){
			val[index] += v;
			index += index & (-index);
		}
	}
	
	void build(vector<int> a){
		for(int i =0;i<(int)a.size();i++){
			add(i,a[i]);
		}
	}
};
 
// fentree ft;
// ft.init(n);
// ft.build(a);
// ft.add(index,val);	// indes = [0,n]
// ft.get(index);

int main(){
	vector<int> a = {1,4,3,2,6,3,7,3};
	fentree ft;
	ft.init(a.size());
	ft.build(a);
	cout<<ft.get(2)<<endl;	//output = 8
	ft.add(1,5);
	cout<<ft.get(2)<<endl;	//output = 13
	return 0;
}


