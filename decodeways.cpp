class Solution {
public:
    int numDecodings(string s) {
        if(s.size()<1)
            return 0;
        if(s[0]=='0')
            return 0;
        if(s.size()==1)
            return 1;
        int val1=1;
        int val2=1;
        for(int i=1;i<s.size();i++){
            int val=0;
            int dig1=s[i]-'0';
            int dig2=(s[i-1]-'0')*10+dig1;
            if(dig1>=1)
                val+=val1;
            if(dig2>=10&&dig2<=26)
                val+=val2;
            val2=val1;
            val1=val;   
        }
        return val1;
    }
};