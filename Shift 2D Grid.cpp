class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        
        int m=grid.size();
        int n=grid[0].size();

        int t=m*n;

        k=k%t;

        vector<vector<int>>ans(m,vector<int>(n));

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int ind=i*n+j;
                int indn=(ind+k)%t;

                int newi=indn/n;
                int newj=indn%n;


                ans[newi][newj]=grid[i][j];

            }
        }

        return  ans;
    }
};
