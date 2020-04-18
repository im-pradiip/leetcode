class Solution {
public:
    bool canJump(vector<int>& nums) {
       /* int len=nums.size();
        if(len==0)
            return false;
        vector<int>res(len,INT_MAX-1);
        res[0]=0;
        for(int i=1;i<len;i++){
            int flag=1;
            for(int j=0;j<i;j++){
                
                if(i<=j+nums[j]){
                    res[i]=min(res[i],res[j]+1);
                    flag=0;
                }
            }
            if(flag==1)
                return false;
        }
        if(res[len-1]==INT_MAX)
            return false;
        else
            return true;
    }*/
    
    //optimised version not mine code
        int len=nums.size();
        int farindex=0;
        for(int i=0;i<len;i++){
            if(farindex<i)
                 return false;
            farindex=max(farindex,nums[i]+i);
            if(farindex>=len-1)
                return true;
        }
        return true;
    }
};