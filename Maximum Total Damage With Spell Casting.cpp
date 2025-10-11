class Solution {
public:
    long long solve(int i,vector<int>&uniq,unordered_map<int,int>&mp,vector<long long int>&dp){
        int n=uniq.size();
        if(i>=n){
            return 0;
        }

        if(dp[i]!=-1){
            return dp[i];
        }

        auto it=lower_bound(uniq.begin(),uniq.end(),uniq[i]+3);
        int index=it-uniq.begin();

        long long int pick=uniq[i]*1ll*mp[uniq[i]]+solve(index,uniq,mp,dp);

        long long int skip=solve(i+1,uniq,mp,dp);

        return dp[i]=max(pick,skip);
    }
    long long maximumTotalDamage(vector<int>& power) {
        
        unordered_map<int,int>mp;
        for(auto i:power){
            mp[i]++;
        }

        vector<int>uniq;
        for(auto x:mp){
            uniq.push_back(x.first);
        }

        sort(uniq.begin(),uniq.end());

        int n=uniq.size();
        vector<long long int>dp(n,-1);

        return solve(0,uniq,mp,dp);


    }
};
