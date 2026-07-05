class Solution {
public:

    const int MOD=1e9+7;

    pair<int,int> dfs(int i,int j,vector<vector<int>>&dp,vector<vector<int>>&ways,vector<string>&board){
        if(i<0 || j<0 || board[i][j]=='X'){
            return {-1,0};
        }

        if(i==0 && j==0){
            return {0,1};
        }

        if(dp[i][j]!=-2){
            return {dp[i][j],ways[i][j]};
        }

        pair<int,int>up=dfs(i-1,j,dp,ways,board);
        pair<int,int>left=dfs(i,j-1,dp,ways,board);
        pair<int,int>diag=dfs(i-1,j-1,dp,ways,board);

        int best=max({up.first,left.first,diag.first});

        if(best==-1){
            dp[i][j]=-1;
            ways[i][j]=0;
            return {-1,0};
        }

        long long count=0;

        if(up.first==best){
            count=(count+up.second)%MOD;
        }
        if(left.first==best){
            count=(count+left.second)%MOD;
        }
        if(diag.first==best){
            count=(count+diag.second)%MOD;
        }

        int val=0;
        if(board[i][j]>='1' && board[i][j]<='9'){
            val=board[i][j]-'0';
        }

        dp[i][j]=best+val;
        ways[i][j]=count;

        return {dp[i][j],ways[i][j]};

    }
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int n=board.size();

        vector<vector<int>>dp(n,vector<int>(n,-2));

        vector<vector<int>>ways(n,vector<int>(n,0));

        pair<int,int>ans=dfs(n-1,n-1,dp,ways,board);

        if(ans.first==-1){
            return {0,0};
        }

        return {ans.first,ans.second};


    }
};
