class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>>dist(n,vector<int>(n,1e9));

        for(auto i:edges){
            int u=i[0];
            int v=i[1];
            int wt=i[2];

            dist[u][v]=wt;
            dist[v][u]=wt;
        }

        for(int i=0;i<n;i++){
            dist[i][i]=0;
        }

        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(dist[i][k]!=1e9 && dist[k][j]!=1e9){
                        dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
                    }
                }
            }
        }

        int city=n;
        int cityno=-1;

        for(int i=0;i<n;i++){
            int count=0;
            for(int adjcity=0;adjcity<n;adjcity++){
                if(dist[i][adjcity]<=distanceThreshold){
                    count++;
                }
            }

            if(count<=city){
                city=count;
                cityno=i;
            }
        }

        return cityno;
    }
};
