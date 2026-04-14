class Solution {
public:
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        
        int n=robot.size();

        sort(robot.begin(),robot.end());
        sort(factory.begin(),factory.end());

        vector<int>nums;
        for(auto &f:factory){
            for(int i=0;i<f[1];i++){
                nums.push_back(f[0]);
            }
        }
        int m=nums.size();

        vector<vector<long long>>dp(n+1,vector<long long>(m+1,0));

        for(int j=0;j<=m;j++){
            dp[n][j]=0;
        }
        for(int i=0;i<n;i++){
            dp[i][m]=1e18;
        }

        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                long long pick=abs(robot[i]-nums[j])+dp[i+1][j+1];

                long long notpick=dp[i][j+1];

                dp[i][j]=min(notpick,pick);
            }
        }

        return dp[0][0];

    }
};
