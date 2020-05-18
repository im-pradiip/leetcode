class Solution {
public:
    /*
    //approach one
    
    // The idea is simple store  the string p in map and every time store the substring of lenth p.size() and
    // check whether it is already present or not if present store the index in vector else do nothing
    unordered_map<char,int>_map;
    bool helper(string str){
        unordered_map<char,int>mp;
        for(int i=0;i<str.size();i++){
            mp[str[i]]++;
            
        }
        cout<<(mp==_map)<<" ";
        //if not present return false
        if(mp==_map)
            return false;
        return true;
    }
    vector<int> findAnagrams(string s, string p) {
        
        vector<int>res;
        if(s.size()==0)
            return res;
        if(s.size()<p.size())
            return res;
        for(int i=0;i<p.size();i++)
            _map[p[i]]++;
        int len=p.size();
        for(int i=0;i<=s.size()-len;i++){
            string str=s.substr(i,len);
            //cout<<str<<" ";
            bool check=helper(str);
            if(!check)
                res.push_back(i);
           // cout<<check<<" ";
        }
        return res;
    }
    */
    //approch 2 count the frequencies
    vector<int> findAnagrams(string s,string p){
        vector<int>checks(26,0);
        vector<int>checkp(26,0);
        int lens=s.size();
        int lenp=p.size();
         vector<int>res;
        if(lens<lenp)
            return res;
       
        for(int i=0;i<lenp;i++){
            checkp[p[i]-'a']++;
        }
        for(int i=0;i<lenp;i++){
            checks[s[i]-'a']++;
        }
        
        if(identical(checks,checkp)){
            res.push_back(0);
        }
        
        for(int i=lenp;i<lens;i++){
            checks[s[i-lenp]-'a']--;
            checks[s[i]-'a']++;
            if(identical(checks,checkp))
                res.push_back(i-lenp+1);
        }
        return res;
    }
    bool identical(vector<int>checks,vector<int>checkp){
        for(int i=0;i<26;i++){
            if(checks[i]!=checkp[i])
                return false;
        }
        return true;
    }
    
};