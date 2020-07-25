// ITMO Segment Tree

struct segtree{
	int size;
	vector<int> vals;
	int neutral = INT_MAX;	//------------> change
		
	void init(int n){
		size = 1;
		while(size < n)size *= 2;
		vals = vector<int>(2*size,neutral);
	}
	
	void build(vector<int> &a, int x, int lx, int rx){
		if(rx-lx == 1){
			if(lx < (int)a.size()){
				vals[x] = a[lx];
			}
			return;
		}
		int m = (lx+rx)/2;
		build(a, 2*x+1, lx, m);
		build(a, 2*x+2, m , rx);
		
		vals[x] = min( vals[2*x + 1] , vals[2*x + 2] );	//------------> change
	}
		
	void set(int i, int v,int x, int lx, int rx){
		if(rx-lx ==1){
			vals[x] = v;
			return;
		}
		int m = (lx + rx)/2;
		
		if(i<m){
			set(i, v, 2*x+1, lx, m);
		}else{
			set(i, v ,2*x+2, m, rx);
		}
		vals[x] = min( vals[2*x + 1] , vals[2*x + 2] );	//------------> change
	}
	
	int get(int l, int r, int x, int lx, int rx){
		if(l >= rx || r <= lx) return neutral;
		if(lx >= l && rx <= r) return vals[x];
		
		int m = (lx + rx)/2;
		return min (get(l,r,2*x+1,lx,m) , get(l,r,2*x+2,m,rx)); //------------> change
		
	}
	
	void build(vector<int> &a){
		build(a,0,0,size);
	}
	
	void set(int i, int v){
		set(i,v,0,0,size);
	}
	
	int get(int l, int r){
		return get(l,r,0,0,size);
	}
};

//first create a segment tree local/global
segtree st;
// initialise it with input vector size 
st.init(n);
// build it with input vector 
st.build(input);
// update a value at index in input vector
st.set(index,value);
// get value of a segment
st.get(left,right);

// l--------r-1, r
// |__________|
