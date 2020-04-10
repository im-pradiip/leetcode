class Solution {
public:
    int rob(vector<int>& nums) {
        int odd_house=0;
        int even_house=0;
        for(int i=0;i<nums.size();i++){
            if(i%2==0)
                even_house=max(even_house+nums[i],odd_house);
            else
                odd_house=max(odd_house+nums[i],even_house);;
        }
        return max(odd_house,even_house);
    }
};

/*   DP solution
class Solution {
public:
    int rob(vector<int>& nums) {
        const int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        if (n == 2) return max(nums[0], nums[1]);
        vector<int> dp(n, 0);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for (int i = 2; i < n; ++i)
            dp[i] = max(dp[i-2] + nums[i], dp[i-1]);
        return dp[n-1];
    }
    //for question 2 7 9  3  1  8
    //dp table     2 7 11 11 12 19    //return 19;
};
*/