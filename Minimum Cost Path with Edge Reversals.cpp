class Solution {
public:

    int dijk(int n,vector<vector<pair<int,int>>>&adj){
        vector<bool>vis(n,false);
        vector<int>dist(n,1e9);

        priority_queue<pair<int,int>>pq;

        pq.push({0,0});
        dist[0]=0;

        while(!pq.empty()){
            int u=pq.top().second;
            pq.pop();

            if(vis[u]){
                continue;
            }

            vis[u]=true;

            for(auto [v,w]:adj[u]){

                if(dist[u]+w<dist[v]){
                    dist[v]=dist[u]+w;
                    pq.push({-dist[v],v});

                }
            }
        }

        if(dist[n-1]==1e9){
            return -1;
        }
        else{
            return dist[n-1];
        }
    }
    int minCost(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>>adj(n);

        for(auto i:edges){
            int u=i[0];
            int v=i[1];
            int w=i[2];

            adj[u].push_back({v,w});
            adj[v].push_back({u,2*w});
        }

        return dijk(n,adj);



        
    }
};
