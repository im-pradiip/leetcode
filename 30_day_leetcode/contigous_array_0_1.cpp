class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> dp;
        int ans = 0, count = 0;
        for(int i = 0; i < nums.size(); i++)
        {
		    // for every 1 found since the beginning of the array, increment
            if(nums[i]) count++;
            else count--; // for every 0 found since the beginning of the array, decrement
			// When count == 0 we know that there is a balance between count of 1s and 0s since the beginning of the arrary
            if(count == 0) ans = max(ans, i + 1);
            else
            {
			    // check if some previous index, has the same balance factor
                auto pos = dp.find(count);
                if(pos != dp.end())
                {
					// if yes, distance = i - pos->second
                    ans = max(ans, i - pos->second);
                }
                else
                {
                    dp.insert({count, i});
                }
            }
        }
        return ans;
    }
};