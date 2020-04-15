class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int leftproduct[nums.size()];
        int rightproduct[nums.size()];
        vector<int>productarray(nums.size());
        leftproduct[0]=1;
        rightproduct[nums.size()-1]=1;
        //compute the left product and fill he leftproduct array
        //let 1 2 4 0 6 be the array
        //then leftproduct[1]=nums[i-1]*leftproduct[i-1]; which is 1
        // similarly leftproduct[2]=2*1=2;
        //similarly leftproduct[3]=4*2=8;
        //similary leftproduct[4]=0*8=0
        //leftproduct array is = 1 1 2 8 0
        
        for(int i=1;i<nums.size();i++){
            leftproduct[i]=nums[i-1]*leftproduct[i-1];
        }
        //similarly rightproduct array = 0 0 0 6 1
        for(int i=nums.size()-2;i>=0;i--){
            rightproduct[i]=nums[i+1]*rightproduct[i+1];
        }
        //final
        // productarray= 0 0 0 48 0
        for(int i=0;i<nums.size();i++){
            productarray[i]=rightproduct[i]*leftproduct[i];
        }
        return productarray;
    }
};