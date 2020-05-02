class Solution {
public:
    int numJewelsInStones(string J, string S) {
        int lenstone=S.size();
        int lenjewel=J.size();
        int count=0;
        unordered_set<char>_set(J.begin(),J.end());
        //inserting jewel while creating unordered_set
        //for(int i=0;i<lenjewel;i++)
          //  _set.insert(J[i]);
        for(int i=0;i<lenstone;i++){
            if(_set.count(S[i]))
                count++;
        }
         //For each stone, check if it is a jewel.
        /*method 2 
        for(int i=0;i<lenstone;i++){
            for(int j=0;j<lenjewel;j++){
                if(J[j]==S[i])
                    count++;
            }
        }*/
        return count;
    }
};