class Solution {
public:
    int ele;
    void binarysearch(vector<int>& nums,int start,int end){
        if(end<start){
            return;
        }
        if(start==end){
            ele=nums[start];
            return;
        }
            int mid=start+(end-start)/2;
        //if mid is even and mid==mid+1 simply we traverse right part
        //else traverse left  part
            if (mid%2 == 0) { 
                if (nums[mid] == nums[mid+1]) 
                    binarysearch(nums, mid+2, end); 
                else
                    binarysearch(nums, start, mid);
            }
        //if mid is odd and mid==mid-1 traverse to right part
        //else traverse to left part
            else{ 
                if (nums[mid] == nums[mid-1]) 
                    binarysearch(nums, mid+1,end); 
                else
                    binarysearch(nums, start, mid-1); 
            } 
    }
    int singleNonDuplicate(vector<int>& nums) {
        if(nums.size()==1)
            return nums[0];
        binarysearch(nums,0,nums.size()-1);
        return ele;
    }
};