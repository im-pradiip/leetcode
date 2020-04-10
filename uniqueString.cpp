class Solution {
public:
    int firstUniqChar(string s) {
        //initialise arr character with 0 count;
        int chararr[256] = {0};
        for(int i=0;i<s.size();i++)
            chararr[s[i]] ++;
        //traverse the string and note the number of occurence of each character
        for(int i=0; i<s.length();i++)
            if(chararr[s[i]]==1)  //if count =1 means it is the first unique character in the string 
                return i;
        return -1;
    }
};