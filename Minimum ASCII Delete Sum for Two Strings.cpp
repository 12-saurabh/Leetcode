class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int n=s1.size();
        int m=s2.size();

        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));

        for(int i=0;i<n;i++){
            dp[i][0]=0;
        }
        for(int j=0;j<m;j++){
            dp[0][j]=0;
        }

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s1[i-1]==s2[j-1]){
                    dp[i][j]=dp[i-1][j-1]+s1[i-1];
                }
                else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }

        int total=0;
        for(char ch:s1){
            total+=ch;
        }
        for(char ch:s2){
            total+=ch;
        }

        return total-2*dp[n][m];



        
    }
};
