class Solution {
private:
    int dfs(int currNode,int parNode,vector<int>adj[],vector<int>&values,int k,int &count){

        int sum=0;

        for(auto neighbr:adj[currNode]){
            if(neighbr!=parNode){
               
                sum+=dfs(neighbr,currNode,adj,values,k,count);
            }

            sum%=k;
        }

        sum+=values[currNode];
        sum%=k;

        if(sum==0){
            count++;
        }

        return sum;
    }

public:
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        
        vector<int>adj[n];

        for(auto edge:edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        int count=0;

        dfs(0,-1,adj,values,k,count);

        return count;





    }
};
