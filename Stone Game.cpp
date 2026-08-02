class Solution {
public:
    int f(int i,int j,vector<int>&piles,vector<vector<int>>&dp){
        if(i>j){
            return 0;
        }

        if(dp[i][j]!=-1){
            return dp[i][j];
        }

        int takei=piles[i]+min(f(i+1,j,piles,dp),f(i+1,j-1,piles,dp));
        int takej=piles[j]+min(f(i,j-2,piles,dp),f(i+1,j-1,piles,dp));

        return dp[i][j]=max(takei,takej);
    }
    bool stoneGame(vector<int>& piles) {
        
        int n=piles.size();
        
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=piles[i];
        }

        vector<vector<int>>dp(n,vector<int>(n,-1));

        return f(0,n-1,piles,dp)>sum/2;

    }
};
