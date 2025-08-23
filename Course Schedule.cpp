class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        int V=numCourses;

        vector<vector<int>>adj(V);

        for(auto i:prerequisites){
            int u=i[0];
            int v=i[1];

            adj[u].push_back(v);

        }

        vector<int>indegree(V);
        for(int i=0;i<V;i++){
            for(auto it:adj[i]){
                indegree[it]++;
            }

        }

        queue<int>q;
        for(int i=0;i<V;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }

        
        int count=0;
        while(!q.empty()){
            int node=q.front();
            q.pop();

            count++;

            for(auto it:adj[node]){

                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                }
            }
        }

        if(count==V){
            return true;
        }
        else{
            return false;
        }
    }
};
