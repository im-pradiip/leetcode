class Solution {
public:
    string stringShift(string s, vector<vector<int>>& shift) {
        //counting total left shifts and right shifts in one go 
        //then after subtracting left right shift 
        //we have to decide whether to perform left shift or right shift
        if(shift.size()==0||s.size()==0)
            return s;
        int countleft=0;
        int countright=0;
        int flag;
        for(int i=0;i<shift.size();i++){
            if(shift[i][0]==0)
                countleft+=shift[i][1];
            else
                countright+=shift[i][1];
        }
        if(countleft==countright)
            return s;
        else if(countleft>countright)
                flag=1;
        else
            flag=0;
        int finalshift=abs(countleft-countright);
        return shiftString(s,finalshift,flag);
    }
    string shiftString(string s, int finalshift,int flag){
       //if flag is 1 perform left shift
        if(flag==1){
            int i;
            for(int j=0;j<finalshift;j++){
                char t=s[0];
                for(i=0;i<s.size()-1;i++){
                    s[i]=s[i+1];
                }
                s[i]=t;
            }
           
        }
        //else perform right shift
        else{
            int k;
            for(int j=0;j<finalshift;j++){
                char t=s[s.size()-1];
                cout<<t;
                for(k=s.size()-2;k>=0;k--){
                    s[k+1]=s[k];
                }
                s[0]=t;
            }
        }
        return s;
    }
};