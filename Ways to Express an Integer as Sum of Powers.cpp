class Solution {
public:

    int const MOD=1e9+7;
    int numberOfWays(int n, int x) {

        vector<int>v;
        int i=1;
        while(pow(i,x)<=n){
            v.push_back(pow(i,x));
            i++;
        }

        int m=v.size();
        
        vector<vector<int>>dp(m+1,vector<int>(n+1,0));

        for(int i=0;i<=m;i++){
            dp[i][0]=1;
        }

        for(int i=1;i<=m;i++){
            for(int sum=1;sum<=n;sum++){
                int nottake=dp[i-1][sum];

                int take=0;
                if(sum>=v[i-1]){
                    take=dp[i-1][sum-v[i-1]];
                }
                dp[i][sum]=(nottake+take)%MOD;
            }
        }
        
        return dp[m][n]; 
        
    }
};
