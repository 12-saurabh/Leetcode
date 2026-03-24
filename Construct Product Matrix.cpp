class Solution {
public:
    const int MOD=12345;
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        
        int n=grid.size();
        int m=grid[0].size();

        vector<vector<int>>ans(n,vector<int>(m));

        int pre=1;
        int  suff=1;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans[i][j]=pre;

                pre=(1ll*pre*grid[i][j])%MOD;
            }
        }

        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                ans[i][j]=(1ll*ans[i][j]*suff)%MOD;

                suff=(1ll*suff*grid[i][j])%MOD;
            }
        }

        return ans;
    }
};
