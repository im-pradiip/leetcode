class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int>checks1(26,0);
        vector<int>checks2(26,0);
        int lens1=s1.size();
        int lens2=s2.size();
        if(lens1>lens2)
            return false;
        for(int i=0;i<lens1;i++){
            checks1[s1[i]-'a']++;
        }
        for(int i=0;i<lens1;i++){
            checks2[s2[i]-'a']++;
        }
        if(identical(checks1,checks2)){
            return true;
        }
        
         for(int i=lens1;i<lens2;i++){
            checks2[s2[i-lens1]-'a']--;
            checks2[s2[i]-'a']++;
            if(identical(checks1,checks2))
                return true;
        }
        return false;
           
    }
     bool identical(vector<int>checks,vector<int>checkp){
        for(int i=0;i<26;i++){
            if(checks[i]!=checkp[i])
                return false;
        }
        return true;
    }
};