
class Solution {
public:
    double soupServings(int n) {

        if(n>=5000){
            return 1.0;
        }

        int N=(n+24)/25;

        vector<vector<double>>dp(N+1,vector<double>(N+1,0.0));

        dp[0][0]=0.5;

        for(int i=1;i<=N;i++){
            dp[0][i]=1.0;
        }

        for(int i=1;i<=N;i++){
            dp[i][0]=0.0;
        }

        for(int a=1;a<=N;a++){
            for(int b=1;b<=N;b++){

                dp[a][b]=0.25*(dp[max(0,a-4)][b]+
                               dp[max(0,a-3)][max(0,b-1)]+
                               dp[max(0,a-2)][max(0,b-2)]+
                               dp[max(0,a-1)][max(0,b-3)]);
            }
        }

        return dp[N][N];

        
    }
};
