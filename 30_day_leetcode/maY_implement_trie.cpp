class Trie { 
    Trie* child[26]; // to create 26children
    bool flag;       //mark end of each word with flag
public:
    /** Initialize your data structure here. */
    Trie() {
        //initialisation of children
        flag=false;
        for(int i=0;i<26;i++){
            child[i]=nullptr;
        }
        
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Trie* curr= this; //this pointing tries all children 
        for(char c: word){//for each character we make a path
            if(!(curr->child[c-'a'])){//if not present insert if already present do not insert
                curr->child[c-'a']=new Trie;
            }
            curr=curr->child[c-'a'];//update curr
        }
        curr->flag=true; // mark ending of each word
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Trie* curr=this;
        for(char c: word){//pointing each character
            curr=curr->child[c-'a'];
            if(!curr)//if not present return false.
                return false;
        }
        if(curr->flag)//if it reach last then true else it is some prefix word which is not insertd
            return true;
        return false;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Trie* curr=this;
        //chck for prefix simply no need to check flag to determine end of word
        for(char c: prefix){
            curr=curr->child[c-'a'];
            if(!curr)
                return false;
        }
        
        return true;;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */