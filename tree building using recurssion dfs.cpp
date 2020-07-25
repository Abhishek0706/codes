void build(int root ,int h,int par){
    height[root] = h;
    parent[root] = par;
    for(int i : node[root]){
        if(i==par)continue;
        build(i,h+1,root);
    }
}


//height of root = 0
//parent of root = 0
build(root,0,0);
