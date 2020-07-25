class Trie{
  public:
    Trie *child[26];
    bool isend;
    
    Trie(){
        for(int i =0;i<26;i++)this->child[i] = NULL;
        this->isend = false;
    }
    
    void insert(string word){
        Trie *tp = this;
        for(int i =0;i<word.size();i++){
            if(tp->child[word[i]-'a']==NULL){
                tp->child[word[i]-'a'] = new Trie;
                tp = tp->child[word[i]-'a'];
            }else{
                tp = tp->child[word[i]-'a'];
            }
        }
        tp->isend = true;
    }
    
    bool isThere(string word){
        Trie *tp = this;
        for(int i =0;i<word.size();i++){
            if(tp->child[word[i]-'a']==NULL)return false;
            tp = tp->child[word[i]-'a'];
        }
        return (tp!=NULL && tp->isend);
    }
};


// initialise and represent
Trie *root = new Trie

// insert
root->insert(s);

//search
root->isThere(s)
