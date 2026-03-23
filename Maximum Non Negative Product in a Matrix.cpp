class Solution {
public:
    const int MOD=1e9+7;
    int maxProductPath(vector<vector<int>>& grid) {

        int n=grid.size();
        int m=grid[0].size();

        vector<vector<long long>>maxi(n,vector<long long>(m,0));
        vector<vector<long long>>mini(n,vector<long long>(m,0));

        maxi[0][0]=grid[0][0];
        mini[0][0]=grid[0][0];

        for(int i=1;i<n;i++){
            mini[i][0]=maxi[i-1][0]*grid[i][0];
            maxi[i][0]=maxi[i-1][0]*grid[i][0];
        }
        for(int i=1;i<m;i++){
            mini[0][i]=maxi[0][i-1]*grid[0][i];
            maxi[0][i]=maxi[0][i-1]*grid[0][i];
        }
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                long long a=mini[i-1][j]*grid[i][j];
                long long b=maxi[i-1][j]*grid[i][j];

                long long c=mini[i][j-1]*grid[i][j];
                long long d=maxi[i][j-1]*grid[i][j];

                mini[i][j]=min({a,b,c,d});
                maxi[i][j]=max({a,b,c,d});
            }
        }

        if(maxi[n-1][m-1]<0){
            return -1;
        }
        return maxi[n-1][m-1]%MOD; 
        
    }
};
