class Solution {
public:

    vector<int> getLps(string pattern){
        int n = pattern.size();
        vector<int> lps(n,0);

        int len = 0;
        for(int i=1;i<n;i++){
            while(len>0 && pattern[i]!= pattern[len]){
                int prevIndex = len - 1;
                int prefixLen = lps[prevIndex];
                int newIndex = prefixLen - 1;
                len = newIndex + 1;
                // in short len = lps[len-1];
            }
            if(pattern[i]==pattern[len]){
                len++;
            }
            lps[i] = len;
        }
        return lps;

    }
    int strStr(string s, string p) {
        
        int n = s.size();
        int m = p.size();
        
        auto lps = getLps(p);

        int len = 0;
        for(int i =0;i<n;i++){
            while(len>0 && s[i]!=p[len]){
                len = lps[len-1];
            }

            if(s[i]==p[len]){
                len++;
            }
            if(len==m){
                return i - len + 1;
            }
        }

        return -1;
    }
};
