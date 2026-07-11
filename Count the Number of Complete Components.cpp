class Solution {
public:

    void dfs(int u,vector<vector<int>>&adj,vector<bool>&vis,vector<int>&comp){
        vis[u]=true;

        comp.push_back(u);

        for(int v:adj[u]){
            if(!vis[v]){
                dfs(v,adj,vis,comp);
            }
        }
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        
        vector<vector<int>>adj(n);

        for(auto i:edges){
            int u=i[0];
            int v=i[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool>vis(n,false);
        int ans=0;

        for(int i=0;i<n;i++){
            if(!vis[i]){
                vector<int>comp;
                dfs(i,adj,vis,comp);

                bool f=true;
                for(int u:comp){
                    if(adj[u].size()!=comp.size()-1){
                        f=false;
                        break;
                    }
                }

                if(f){
                    ans++;
                }
            }            
        }

        return ans;

    }
};
