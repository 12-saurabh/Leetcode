class Solution {
public:

    int dx[4]={1,-1,0,0};
    int dy[4]={0,0,1,-1};

    bool bfs(vector<vector<int>>&dist,int safe){
        int n=dist.size();

        if(dist[0][0]<safe){
            return false;
        }

        queue<pair<int,int>>q;
        vector<vector<bool>>vis(n,vector<bool>(n,false));

        q.push({0,0});
        vis[0][0]=true;

        while(!q.empty()){
            auto [x,y]=q.front();
            q.pop();

            if(x==n-1 && y==n-1){
                return true;
            }

            for(int k=0;k<4;k++){
                int nx=x+dx[k];
                int ny=y+dy[k];

                if(nx>=0 && nx<n && ny>=0 && ny<n && !vis[nx][ny] && dist[nx][ny]>=safe){
                    vis[nx][ny]=true;
                    q.push({nx,ny});
                }
            }
        }

        return false;
    }
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        
        int n=grid.size();

        queue<pair<int,int>>q;
        vector<vector<int>>dist(n,vector<int>(n,INT_MAX));
        vector<vector<int>>vis(n,vector<int>(n,false));

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    dist[i][j]=0;
                    vis[i][j]=true;
                    q.push({i,j});
                }
            }
        }

        while(!q.empty()){
            auto [x,y]=q.front();
            q.pop();

            for(int k=0;k<4;k++){
                int nx=x+dx[k];
                int ny=y+dy[k];

                if(nx>=0 && nx<n && ny>=0 && ny<n && !vis[nx][ny]){
                    vis[nx][ny]=true;
                    dist[nx][ny]=dist[x][y]+1;
                    q.push({nx,ny});
                }
            }
        }

        int s=0;
        int e=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                e=max(e,dist[i][j]);
            }
        }

        int ans=0;

        while(s<=e){
            int mid=(e+s)/2;

            if(bfs(dist,mid)){
                ans=mid;
                s=mid+1;
            }
            else{
                e=mid-1;
            }
        }

        return ans;
    }
};
