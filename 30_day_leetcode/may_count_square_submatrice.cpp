class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int m=matrix.size();
        if(m==0)
            return 0;
        int n=matrix[0].size();
        int result=0;
        vector<vector<int>>vec(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0||j==0||matrix[i][j]==0)
                    vec[i][j]=matrix[i][j];
                else
                    vec[i][j]=min(vec[i-1][j-1],min(vec[i-1][j],vec[i][j-1]))+1;
                result+=vec[i][j];
            }
        }
        return result;
    }
};