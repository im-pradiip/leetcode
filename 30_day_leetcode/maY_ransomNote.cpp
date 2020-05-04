class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int>_map;
        //making map of each distinct character and store total occurences
        for(int i=0;i<magazine.size();i++){
            char chr=magazine[i];
            if(_map.find(chr)==_map.end()){
                _map.insert({chr,1});
            }
            else
                _map[chr]=_map[chr]+1;
                
        }
        //if ransomNote char c not in magazine return false
        //if present then check count if count>0 means we make ransomNote 
        //if count = 0 return false
        // at last all okay return true;
        for(char c:ransomNote){
            if(_map.find(c)==_map.end()){
                return false;
            }
            
            int cnt=_map[c];
            if(cnt>0)
                _map[c]=--cnt;
            else
                return false;
        }
        return true;
    }
};