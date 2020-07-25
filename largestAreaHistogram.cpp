int largestAreaHistogram(vector<int> A) {
           
A.insert(A.begin(),0); // to make sure Stack will never empty while running while loop
A.push_back(0); // at the end it will flush stack if stack contain elements 

int len=A.size();
int i,res=0;
stack<int>s;
s.push(0);
for(int i=1;i<len;i++){
    while(A[i]<A[s.top()]){
        int tp=s.top();
        s.pop();
        res=max(res,A[tp]*(i-s.top()-1));
    }
    s.push(i);
}
return res;
}