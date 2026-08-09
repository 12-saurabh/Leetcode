class Solution {
public:
    
    int f(int i,int m,vector<int>&piles,vector<vector<int>>&dp){
        
        int n=piles.size();

        if(i==n){
            return 0;
        }

        if(dp[i][m]!=-1){
            
            return dp[i][m];
        }

        int ans=INT_MIN;
        int sum=0;
        for(int x=1;x<=2*m;x++){

            int idx=i+x-1;
            
            if(idx>=n){
                break;
            }
            
            sum+=piles[idx];
            
            ans=max(ans,sum-f(idx+1,max(x,m),piles,dp));
        }
        return dp[i][m]=ans;
    }
    int stoneGameII(vector<int>& piles) {

        int n=piles.size();
        
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        
        int sum=accumulate(piles.begin(),piles.end(),0);
        
        int ans=f(0,1,piles,dp);
        return (sum+ans)/2;
    }
};
