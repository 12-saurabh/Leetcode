class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        
        vector<vector<pair<int,int>>>adj(n+1);

        for(auto &i:roads){
            int u=i[0];
            int v=i[1];
            int wt=i[2];

            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});

        }

        vector<int>vis(n+1,0);
        queue<int>q;
        q.push(1);
        vis[1]=1;


        int ans=INT_MAX;

        while(!q.empty()){
            int u=q.front();
            q.pop();


            for(auto i:adj[u]){
                int v=i.first;
                int wt=i.second;

                ans=min(ans,wt);

                if(!vis[v]){
                    vis[v]=1;
                    q.push(v);
                }
            }
        }

        return ans;
    }
};
