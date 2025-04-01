class Solution {
public:

    long long f(int i,vector<vector<int>>& questions){
        int n=questions.size();

        vector<long long>dp(n,0);

        dp[n-1]=questions[n-1][0];

        for(int i=n-2;i>=0;i--){
            long long  pick=questions[i][0];
            int next=i+questions[i][1]+1;
            if(next<n){
                pick+=dp[next];
            }

            long long notpick=dp[i+1];

            dp[i]=max(pick,notpick);

        }
        return dp[0];
    }

    long long mostPoints(vector<vector<int>>& questions) {

        long long ans=f(0,questions);
        return ans;
        
    }
};
