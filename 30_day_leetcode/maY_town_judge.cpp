class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        unordered_map<int,int>_map;
        int count=0;
        int guest=0;
        int flag=0;
        //just count the total person know a town judge
        //if it is N-1
        //means there may be a town judge but there is no surity.
        //for surity the town judge dont know any other person
        //if both condidtion satisfy there is a town judge and return the guest as it stores the town judge
        //else if one the condition voilates return -1;
        //if N=1 means there is no a->b relation means 1 itself the town judge
        if(N==1)
            return 1;
        for(int i=0;i<trust.size();i++){
            _map[trust[i][1]]++;
            if(count<_map[trust[i][1]]){
                count=_map[trust[i][1]];
                guest=trust[i][1];
            }
        }
        if(count==N-1)
            flag=1;
        else
            return -1;
        for(int i=0;i<trust.size();i++){
            if(trust[i][0]==guest&&flag==1){
                return -1;
            }
        }
        return guest;
    }
};