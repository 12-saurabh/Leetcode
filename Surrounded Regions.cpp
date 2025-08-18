class Solution {
private:
    
    void dfs(int i,int j,vector<vector<int>>&vis,vector<vector<char>>&board,int delRow[],int delCol[]){

        int n=board.size();
        int m=board[0].size();

        vis[i][j]=1;

        // int delRow[]={-1,0,+1,0};
        // int delCol[]={0,+1,0,-1};

        for(int k=0;k<4;k++){
            int newi=i+delRow[k];
            int newj=j+delCol[k];

            if(newi>=0 && newi<n && newj>=0 && newj<m && !vis[newi][newj] && board[newi][newj]=='O'){
                dfs(newi,newj,vis,board,delRow,delCol);
            }
        }
    }
public:
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();

        int delRow[]={-1,0,+1,0};
        int delCol[]={0,+1,0,-1};

        vector<vector<int>>vis(n,vector<int>(m,0));
        
        for(int j=0;j<m;j++){
            if(!vis[0][j] && board[0][j]=='O'){
                dfs(0,j,vis,board,delRow,delCol);

            }
            if(!vis[n-1][j] && board[n-1][j]=='O'){
                dfs(n-1,j,vis,board,delRow,delCol);
            }
        }

        for(int i=0;i<n;i++){
            if(!vis[i][0] && board[i][0]=='O'){
                dfs(i,0,vis,board,delRow,delCol);

            }
            if(!vis[i][m-1] && board[i][m-1]=='O'){
                dfs(i,m-1,vis,board,delRow,delCol);
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && board[i][j]=='O'){
                    board[i][j]='X';
                }
            }
        }


    }
};
