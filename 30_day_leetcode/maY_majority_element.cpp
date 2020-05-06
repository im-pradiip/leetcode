class Solution {
public:
    int majorityElement(vector<int>& nums) {
       
        if (nums.empty()) return {};
        return _majorityElementOfK(nums); 
    }
    // here just maping each elemnt with their total occurence 
    //that element which has occcurence greater than n/2 is our majority element
    int _majorityElementOfK(const vector<int>& nums){
        unordered_map<int, int> m; 
        int v;
        for(int i = 0; i < nums.size(); i++) 
            m[nums[i]]++;  
        for(auto i : m) 
        { 
            if(i.second > nums.size() / 2) 
            {  
                
                v=i.first;
                break;
            } 
        } 
        return v;
    } 
    
    //approach 2  moore approach
    // assuming first element as majority element and if same element occur next time we just increase
    // the count and if different we just decrease the counce if count becomes zero we make that element as           //majority element
    // by this we just sure that the majority element must be greater than remaing n/2 elements  hence by             //increasing and decreasing     
    //we get the count>0 and also get the majority element
    
    /* int majorityElement(vector<int>& nums) {
        int n=nums.size();
        int major;//=nums[0];
        int count=0;
        for(int i=0;i<n;i++){
            if(count==0){
                count++;
                major=nums[i];
            }
            else if(nums[i]==major)
                count++;
            else
                count--;
        }
        return major;
    }
    
    //approach 3 just sort the array and print the n/2 index element which is majority element
    /*
    int n=nums.size();
    sort(nums.begin(),nums.end());
    return nums[n/2];
    }*/
};