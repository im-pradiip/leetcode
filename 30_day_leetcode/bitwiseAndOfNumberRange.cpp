class Solution {
public:
    //brute force approach which passes 8556 test cases out of 8566
    /*int rangeBitwiseAnd(int m, int n) {
        int ans=m;
        for(int i=m;i<=n;i++){
            ans=ans&i;
        }
        return ans;
    }*/
    //using shift operation
    //if the both number is in range of same number of bits required to represent both number in binary
    //then there must be an answer 
    //else anser is zero
    //we get ansewer upto the equal right most bit ie 
    // 28= 11100
    //24= 11000
    //last two right significant bit matches hence anser is 11000 ie 24
    //28->14->7->3
    //24->12->6->3
    //equal then shifting 3 three times as count=3;
    //3->6->12->24
    int rangeBitwiseAnd(int m, int n){
        int count=0;
        while(m<n){
            m>>=1;
            n>>=1;
            count++;
        }
        return m<<count;
    }
};