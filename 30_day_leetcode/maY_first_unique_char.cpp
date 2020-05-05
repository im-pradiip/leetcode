class Solution {
public:
    int firstUniqChar(string s) {
        int chararr[128] = {0};
        //here just counting the total occurence of each character in a string to chcek further
        //if the counting is 1 means it is the first unique non repeating character in the given string
        for(int i=0;i<s.size();i++)
            chararr[s[i]] ++;
        for(int i=0; i<s.length();i++)
            if(chararr[s[i]]==1) return i;
        return -1;
    }
};