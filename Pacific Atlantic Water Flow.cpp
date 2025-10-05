class Solution {
public:

    void dfs(int i,int j,vector<vector<int>>&heights,vector<vector<bool>>&vis){

        int n=heights.size();
        int m=heights[0].size();

        vis[i][j]=true;

        int dr[]={-1,0,1,0};
        int dc[]={0,1,0,-1};

        for(int k=0;k<4;k++){
            int nr=i+dr[k];
            int nc=j+dc[k];

            if(nr>=0 && nr<n && nc>=0 && nc<m && !vis[nr][nc] && heights[nr][nc]>=heights[i][j]){
                dfs(nr,nc,heights,vis);
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        
        int n=heights.size();
        int m=heights[0].size();

        vector<vector<bool>>pac(n,vector<bool>(m,false));
        vector<vector<bool>>atl(n,vector<bool>(m,false));

        for(int i=0;i<n;i++){
            dfs(i,0,heights,pac);
            dfs(i,m-1,heights,atl);
        }

        for(int j=0;j<m;j++){
            dfs(0,j,heights,pac);
            dfs(n-1,j,heights,atl);
        }

        vector<vector<int>>ans;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(pac[i][j] && atl[i][j]){
                    ans.push_back({i,j});
                }
            }
        }

        return ans;

    }
};
