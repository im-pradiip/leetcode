class Solution {
public:
    string removeKdigits(string num, int k) {
        string res=num;
        //if all the digits are in increasing order than we will delete the last digit , otherwise we will delete         //a digit for which next digit is smaller.
        
        for(int i=0;i<k;i++){
            int j=0;
            while(j<res.size()&&res[j]<=res[j+1])
                j++;
            res.erase(res.begin()+j);
        }
        
        //need to remove all leading zeroes.
        while(res.size()>0&&res[0]=='0')
            res.erase(res.begin()+0);
        
        //if res is empty return 0
        if(res.size()==0)
            return "0";
        return res;
    }
};