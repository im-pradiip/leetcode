class Solution {
public:
    //brute force approach
    /*int subarraySum(vector<int>& nums, int k) {
        int count=0;
        for(int i=0;i<nums.size();i++){
            int sum=0;
            for(int j=i;j<nums.size();j++){
                sum+=nums[j];
                //cout<<sum<<" ";
                if(sum==k){
                    count++;
                }
            }
        }
        return count;
    }*/
    //bY using map
    int subarraySum(vector<int>& nums,int k){
        if(nums.size()==0)
            return 0;
        int count=0;
        unordered_map<int,int>mp;
        int currsum=0;
        for(int i:nums){
            currsum+=i;
            if(currsum==k)//if currentsum=k if we get the sum of k count++;
                count++;
            if(mp.find(currsum-k)!=mp.end()){//if (currsum-k)means prefix already present in a map 
                                            // just simply add the number of times it occured earlier
                count+=mp[currsum-k];
            }
            if(mp.find(currsum)!=mp.end())// if map contains currsum already just increment it or initialise that sum with 1;
                mp[currsum]+=1;
            else
                mp[currsum]=1;
        }
        return count;
        
    }
};