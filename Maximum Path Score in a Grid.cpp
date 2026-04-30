class Solution {
public:
    int f(int i,int j,int cost,int k,vector<vector<int>>&grid,vector<vector<vector<int>>>&dp){
        if(i<0 || j<0){
            return -1e9;
        }

        if(i==0 && j==0){
            return grid[0][0];
        }

        if(dp[i][j][cost]!=-1e9){
            return dp[i][j][cost];
        }

        int ncost;
        if(grid[i][j]>0){
            ncost=cost+1;
        }
        else{
            ncost=cost+0;
        }

        if(ncost>k){
            return -1e9;
        }

        int up=f(i-1,j,ncost,k,grid,dp);
        int left=f(i,j-1,ncost,k,grid,dp);

        return dp[i][j][cost]=max(up,left)+grid[i][j];
    }
    int maxPathScore(vector<vector<int>>& grid, int k) {
        
        int m=grid.size();
        int n=grid[0].size();

        vector<vector<vector<int>>>dp(m+1,vector<vector<int>>(n+1,vector<int>(k+1,-1e9)));

        int ans=f(m-1,n-1,0,k,grid,dp);

        if(ans<0){
            return -1;
        }

        return ans;
    }
};
