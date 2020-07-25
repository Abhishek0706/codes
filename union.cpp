vector<int> u_parent;
vector<int> u_rank;

int u_get(int a){
	return u_parent[a]=(u_parent[a]==a?a:u_get(u_parent[a]));
}

void u_union(int a,int b){
	a = u_get(a);
	b = u_get(b);
	if(u_rank[a]==u_rank[b]) u_rank[a]++;
	if(u_rank[a]>u_rank[b])u_parent[b]=a;
	else u_parent[a]=b;
}

// Initialise all parent to itself :: parent[i] = i
// Initialise all rank to 0 :: rank[i] = 0


// by size

vector<int> u_parent;
vector<int> u_size;

int u_get(int a){
	return u_parent[a]=(u_parent[a]==a?a:u_get(u_parent[a]));
}

void u_union(int a,int b){
	a = u_get(a);
	b = u_get(b);
	if(u_size[a]>u_size[b]){
		u_parent[b]=a;
		u_size[b] += u_size[a];
	}
	else {
		u_parent[a]=b;
		u_size[a] += u_size[b];
	}
	
}

// Initialise all parent to itself :: parent[i] = i
// Initialise all size to 1 :: rank[i] = 1
