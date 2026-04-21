class DisjointSet{
    vector<int>rank;
    vector<int>parent;

public:
    DisjointSet(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);

        for(int i=0;i<n;i++){
            parent[i]=i;
        }
    }
    int find_Upar(int node){
        if(node==parent[node]){
            return node;
        }

        return parent[node]=find_Upar(parent[node]);
    }

    void unionByrank(int u,int v){
        int ult_u=find_Upar(u);
        int ult_v=find_Upar(v);

        if(ult_u==ult_v){
            return;
        }
        if(rank[ult_u]<rank[ult_v]){
            parent[ult_u]=ult_v;
        }
        else if(rank[ult_v]<rank[ult_u]){
            parent[ult_v]=ult_u;
        }
        else{
            parent[ult_v]=ult_u;
            rank[ult_u]++;
        }
    }
    
};
class Solution {
public:
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int n=target.size();
        DisjointSet d(n);

        for(auto &i:allowedSwaps){
            d.unionByrank(i[0],i[1]);
        }

        unordered_map<int,vector<int>>mp;
        for(int i=0;i<n;i++){
            int par=d.find_Upar(i);
            mp[par].push_back(i);
        }

        int dis=0;
        for(auto &i:mp){
            auto &ind=i.second;

            unordered_map<int,int>freq;

            for(int idx:ind){
                freq[source[idx]]++;
            }

            for(int idx:ind){
                if(freq[target[idx]]>0){
                    freq[target[idx]]--;
                }
                else{
                    dis++;
                }
            }
        }

        return dis;

    }
};
