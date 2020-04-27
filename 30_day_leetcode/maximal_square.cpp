class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m=matrix.size();
        if(m==0)
            return 0;
        int n=matrix[0].size();
        int maximum=0;
        vector<vector<int>>vec(m,vector<int>(n,0));
        // if we met with zero we just simply fill with zero 
        // if we encounter 1 then we check the minimum among the three adjacent cells that is i-1 j-1 && i-1 j &&            i j-1 plus 1;
        // 1 0 1 0 0
        // 1 0 1 1 1
        // 1 1 1 2 2
        // 1 0 0 1 0
        // hence the  maximum is 2 and we return 2*2=4
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0||j==0||matrix[i][j]=='0')
                    vec[i][j]=matrix[i][j]-'0';
                else{
                    vec[i][j]=min(vec[i-1][j-1],min(vec[i-1][j],vec[i][j-1]))+1;
                }
                maximum=max(maximum,vec[i][j]);
            }
        }
        return maximum*maximum;
    }
};