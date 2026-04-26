class Solution {
public:
    bool dfs(int i,int j,int parx,int pary,vector<vector<char>>&grid,vector<vector<bool>>&vis){
        int m=grid.size();
        int n=grid[0].size();

        vis[i][j]=true;

        int dr[]={-1,0,1,0};
        int dc[]={0,1,0,-1};

        for(int k=0;k<4;k++){
            int nr=i+dr[k];
            int nc=j+dc[k];

            if(nr>=0 && nr<m && nc>=0 && nc<n && grid[nr][nc]==grid[i][j]){
                if(vis[nr][nc] && nr!=parx && nc!=pary){
                    return true;
                }
                else if(!vis[nr][nc]){
                    if(dfs(nr,nc,i,j,grid,vis)){
                        return true;
                    }
                }
            }
        }

        return false;
    }
    bool containsCycle(vector<vector<char>>& grid) {
        
        int m=grid.size();
        int n=grid[0].size();

        vector<vector<bool>>vis(m,vector<bool>(n,false));

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!vis[i][j]){
                    if(dfs(i,j,-1,-1,grid,vis)){
                        return true;
                    }
                }
            }
        }

        return false;

    }
};
