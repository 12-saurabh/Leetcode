class Solution {
public:
    int f(int i,int j,int ntr,vector<vector<int>>&coins,vector<vector<vector<int>>>&dp){
        if(i==0 && j==0){
            if(coins[i][j]<0 && ntr>0){
                return 0;
            }

            return coins[i][j];
        }
        if(i<0 || j<0){
            return -1e9;
        }

        if(dp[i][j][ntr]!=-1e9){
            return dp[i][j][ntr];
        }

        int pick=coins[i][j]+max(f(i-1,j,ntr,coins,dp),f(i,j-1,ntr,coins,dp));

        int notpick=-1e9;
        if(ntr>0 && coins[i][j]<0){
            notpick=max(f(i-1,j,ntr-1,coins,dp),f(i,j-1,ntr-1,coins,dp));
        }

        return dp[i][j][ntr]=max(notpick,pick);
    }
    int maximumAmount(vector<vector<int>>& coins) {
        int n=coins.size();
        int m=coins[0].size();

        vector<vector<vector<int>>>dp(n,vector<vector<int>>(m,vector<int>(3,-1e9)));

        return f(n-1,m-1,2,coins,dp);
        
    }
};
