class Solution {
public:
    int maxSubarraySumCircular(vector<int>& A) {
        int maxsum=INT_MIN;
        int minsum=INT_MAX;
        int maxsum_ending_at=0;
        int minsum_ending_at=0;
        int totalsum=0;
        for(int x:A){
            totalsum+=x;
            maxsum_ending_at=max(maxsum_ending_at+x,x);
            maxsum=max(maxsum,maxsum_ending_at);
            minsum_ending_at=min(minsum_ending_at+x,x);
            minsum=min(minsum,minsum_ending_at);
        }
        if(maxsum>0)
            return max(maxsum,totalsum-minsum);
        return maxsum;
    }
};