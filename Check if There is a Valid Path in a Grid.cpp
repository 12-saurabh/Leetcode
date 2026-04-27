class Solution {
public:
    bool dfs(int i,int j,vector<vector<int>>&grid,vector<vector<bool>>&vis,vector<vector<pair<int,int>>>&dir){
        int m=grid.size();
        int n=grid[0].size();

        vis[i][j]=true;

        if(i==m-1 && j==n-1){
            return true;
        }

        int v=grid[i][j];

        for(int k=0;k<dir[v].size();k++){
            int ni=i+dir[v][k].first;
            int nj=j+dir[v][k].second;

            bool is=false;

            if(ni>=0 && ni<m && nj>=0 && nj<n){
                int newv=grid[ni][nj];

                for(auto [dx,dy]:dir[newv]){
                    if(ni+dx==i && nj+dy==j){
                        is=true;
                        break;
                    }
                }

                if(!is){
                    continue;
                }

                if(!vis[ni][nj]){
                    if(dfs(ni,nj,grid,vis,dir)){
                        return true;
                    }
                }
            }
        }

        return false;
    }
    bool hasValidPath(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();

        vector<vector<bool>>vis(m,vector<bool>(n,false));

         vector<vector<pair<int,int>>>dir={
            {{{0,0},{0,0}}},{{{0,-1},{0,1}}},{{{1,0},{-1,0}}},
            {{{0,-1},{1,0}}},{{{0,1},{1,0}}},{{{0,-1},{-1,0}}},
            {{{0,1},{-1,0}}},
        };

        return dfs(0,0,grid,vis,dir);
        
    }
};
