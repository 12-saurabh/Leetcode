class Solution {
public:
//   Memoiation!
    // int f(int i,int j,vector<vector<int>>& matrix,vector<vector<int>>&dp){
        

    //     if(j<0 || j>=matrix[0].size()){
    //         return 1e9;
    //     }

    //     if(i==0){
    //         return matrix[0][j];
    //     }
    //     if(dp[i][j]!=-1){
    //         return dp[i][j];
    //     }

    //     int up=matrix[i][j]+f(i-1,j,matrix,dp);
    //     int ul=matrix[i][j]+f(i-1,j-1,matrix,dp);
    //     int ur=matrix[i][j]+f(i-1,j+1,matrix,dp);

    //     return dp[i][j]=min(up,min(ul,ur));
    // }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        // Tabulation!

        // int n=matrix.size();
        // int m=matrix[0].size();

        // vector<vector<int>>dp(n,vector<int>(m,-1));

        // for(int j=0;j<m;j++){
        //     dp[0][j]=matrix[0][j];
        // }

        // for(int i=1;i<n;i++){
        //     for(int j=0;j<m;j++){
        //         int up=matrix[i][j]+dp[i-1][j];
        //         int ul=matrix[i][j];
        //         if(j-1>=0){
        //             ul+=dp[i-1][j-1];
        //         }
        //         else{
        //             ul+=1e9;
        //         }
        //         int ur=matrix[i][j];
        //         if(j+1<m){
        //             ur+=dp[i-1][j+1];
        //         }
        //         else{
        //             ur+=1e9;
        //         }

        //         dp[i][j]=min(up,min(ul,ur));
        //     }
        // }


        // int mini=1e9;
        // for(int j=0;j<m;j++){
        //     mini=min(mini,dp[n-1][j]);
        // }

        // return mini;

//  Space Otimization!

        int n=matrix.size();
        int m=matrix[0].size();

        vector<int>prev(m,0);
        vector<int>curr(m,0);

        for(int j=0;j<m;j++){
            prev[j]=matrix[0][j];
        }

        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                int up=matrix[i][j]+prev[j];
                int ul=matrix[i][j];
                if(j-1>=0){
                    ul+=prev[j-1];
                }
                else{
                    ul+=1e9;
                }
                int ur=matrix[i][j];
                if(j+1<m){
                    ur+=prev[j+1];
                }
                else{
                    ur+=1e9;
                }

                curr[j]=min(up,min(ul,ur));
            }
            prev=curr;
        }


        int mini=1e9;
        for(int j=0;j<m;j++){
            mini=min(mini,prev[j]);
        }

        return mini;


    }
};
