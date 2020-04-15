class Solution {
public:
    static bool compare(pair<int,int>p1,pair<int,int>p2){
        if(p1.second==p2.second)
            return p1.first<p2.first;
        return p1.second>p2.second;
    }
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>ma;
        for(int i=0;i<nums.size();i++)
            ma[nums[i]]++;
        vector<pair<int,int>>f(ma.begin(),ma.end());
        sort(f.begin(),f.end(),compare);
        vector<int>vec;
        for(int i=0;i<k;i++)
            vec.push_back(f[i].first);
        return vec;
    }
};