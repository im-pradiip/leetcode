class Solution {
public:
    bool isPerfectSquare(int num) {
        if(num==0||num==1)
            return true;
        int flag=0;
        for(long i=2;i*i<=num;i++){
            if(i*i==num){
                flag=1;
                break;
            }
        }
        if(flag==1)
            return true;
        return false;
    }
};