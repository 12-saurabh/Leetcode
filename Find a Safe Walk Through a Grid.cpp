class Solution {
public:
    
    bool dfs(vector<vector<int>>&grid,int i,int j,vector<vector<int>>&healthgrid,int health){

        int m=grid.size();
        int n=grid[0].size();

        if(i<0 || i>=m || j<0 || j>=n || health<=0){
            return false;
        }

        health-=grid[i][j];

        if(health<=0){
            return false;
        }

        if(i==m-1 && j==n-1){
            return true;
        }

        if(health<=healthgrid[i][j]){
            return false;
        }

        healthgrid[i][j]=health;

        bool ans=dfs(grid,i-1,j,healthgrid,health)||
                dfs(grid,i,j+1,healthgrid,health)||
                dfs(grid,i+1,j,healthgrid,health)||
                dfs(grid,i,j-1,healthgrid,health);

        return ans;

    }
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        
        int m=grid.size();
        int n=grid[0].size();

        vector<vector<int>>healthgrid(m,vector<int>(n,-1));

        return dfs(grid,0,0,healthgrid,health);
    }
};
