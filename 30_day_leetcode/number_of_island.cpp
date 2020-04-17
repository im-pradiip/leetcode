class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if(grid.size()==0||grid[0].size()==0)
            return 0;
        int numofisland=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                //if grid[i][j]==1 start exploring island at its adjacent else 0 do nothing
                if(grid[i][j]=='1')
                    numofisland+=dfs(grid,i,j);
            }
        }
        return numofisland;
    }
    int dfs(vector<vector<char>>& grid,int i,int j){
        if(i<0||i>=grid.size()||j<0||j>=grid[0].size()||grid[i][j]=='0')
            return 0;
        grid[i][j]='0';
        //making grid[i][j]=0 so that next time it cannot added to the result
        //checking all its adjacent and amke all the adjacent to zero
        //recursively after making  all adjacent 1s to 0s it return 1
        dfs(grid,i+1,j);
        dfs(grid,i-1,j);
        dfs(grid,i,j+1);
        dfs(grid,i,j-1);
        
        return 1;
    }
};