    vector<int> rightsp(n,-1);
    stack<int> st;
    for(int i = 0;i<n;i++){
        while(!st.empty() && A[i]>A[st.top()]){
            rightsp[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }
    while(!st.empty()){
        rightsp[st.top()] = -1;
        st.pop();
    }
    
