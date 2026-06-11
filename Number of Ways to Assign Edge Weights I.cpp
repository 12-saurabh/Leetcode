class Solution {
public:
    
    const int MOD=1e9+7;
    int dfs(int curr,int parent,vector<vector<int>>&adj){
        int dep=0;

        for(auto i:adj[curr]){
            if(i==parent){
                continue;
            }

            dep=max(dep,dfs(i,curr,adj)+1);
        }

        return dep;
    }
    int assignEdgeWeights(vector<vector<int>>& edges) {
        
        int n=edges.size()+1;

        vector<vector<int>>adj(n+1);

        for(auto i:edges){
            int u=i[0];
            int v=i[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int dep=dfs(1,0,adj);

        long long ans=1;

        while(--dep){
            ans=(ans*2)%MOD;
        }

        return ans;
    }
};
