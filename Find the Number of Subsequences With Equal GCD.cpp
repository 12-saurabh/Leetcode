class Solution {
public:
    const int MOD=1e9+7;
    int f(int i,int g1,int g2,vector<int>&nums,vector<vector<vector<int>>>&dp){
        int n=nums.size();
        if(i==n){
            if(g1>0 && g2>0 && g1==g2){
                return 1;
            }
            else{
                return 0;
            }
        }

        if(dp[i][g1][g2]!=-1){
            return dp[i][g1][g2];
        }

        int ans=0;

        ans=f(i+1,g1,g2,nums,dp);
        ans=(ans+f(i+1,gcd(g1,nums[i]),g2,nums,dp))%MOD;
        ans=(ans+f(i+1,g1,gcd(g2,nums[i]),nums,dp))%MOD;

        return dp[i][g1][g2]=ans;

        
    }
    int subsequencePairCount(vector<int>& nums) {
        
        int n=nums.size();
        int maxi=*max_element(nums.begin(),nums.end());

        vector<vector<vector<int>>>dp(n,vector<vector<int>>(maxi+1,vector<int>(maxi+1,-1)));

        return f(0,0,0,nums,dp);
    }
};
