class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        
        int n=grid.size();
        int m=grid[0].size();

        vector<vector<int>>precompute(n+1,vector<int>(m+1,0));

        int count=0;

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){


                precompute[i][j]=grid[i-1][j-1]+precompute[i-1][j]+precompute[i][j-1]-precompute[i-1][j-1];
                
                if(precompute[i][j]<=k){
                    count++;
                }
            }
        }

        return count;
    }
};
