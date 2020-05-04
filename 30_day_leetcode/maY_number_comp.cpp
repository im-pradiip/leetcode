class Solution {
public:
    int findComplement(int num) {
        int bitsreq=0;
        int temp=num;
        //suppose numbr is 19 then we have required 5 bits to store 19 in binary 
        //hence this while loop counting this;
        while(num>0){
            num=num/2;
            bitsreq++;
        }
        int nums[bitsreq];
        num=temp;
        //this create a array of binary conversion of the number in compliment form 
        //that is 1 0 0 1 1 to --->0 1 1 0 0 
        for(int i=bitsreq-1;i>=0;i--){
            int x=num%2;
            if(x==1)
                nums[i]=0;
            else
                nums[i]=1;
            num=num/2;
        }
        
        int compNum=0;
        int k=0;
        //here it is converting it back to integer form 
        for(int i=bitsreq-1;i>=0;i--){
            compNum+=nums[i]*pow(2,k++);
        }
        return compNum;
    }
};