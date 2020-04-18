class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if(grid.size()==0||grid[0].size()==0)
            return 0;
        int row=grid.size();
        int col=grid[0].size();
        vector<vector<int>>res(row,vector<int>(col));
        res[0][0]=grid[0][0];
        //first adding whole first row into res matrix
        //adding whole first column into res matrix
        //example if grid is 2 3 4 5
                        //   1 3 5 6
                        //   3 2 1 3
        
        
        //res matrix is      2 5 9  14
                        //   3 
                        //   6
        
        // now by applying from i=1 to row-1
        //                      j=1 to col-1
        //                      res[i][j]=gris[i][j]+min(res[i-1][j],res[i][j-1]);
        
        //final res matrix is  2 5 9  14
        //                     3 6 11 17
        //                     6 8 9  12*
        
        // answer =12
        for(int i=1;i<grid[0].size();i++){
            res[0][i]=res[0][i-1]+grid[0][i];
        }
        for(int j=1;j<grid.size();j++){
            res[j][0]=res[j-1][0]+grid[j][0];
        }
        for(int i=1;i<row;i++){
            for(int j=1;j<col;j++){
                res[i][j]=grid[i][j]+ min(res[i-1][j],res[i][j-1]);
            }
        }
        return res[row-1][col-1];
    }
};
