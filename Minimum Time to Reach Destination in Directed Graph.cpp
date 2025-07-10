
class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges) {
        
        vector<vector<array<long long, 3>>> g(n);
        
        vector<vector<int>> d = edges;
        
        for (auto& e : edges) {
            
            int u = e[0];
            
            int v = e[1];
            
            long long s = e[2];
            
            long long end = e[3];
            
            g[u].push_back({v, s, end});
        }
        
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
        
    pq.push({0, 0}); 
        
        vector<long long> mt(n, LLONG_MAX);
        
    mt[0] = 0;
        
        while (!pq.empty()) {
            
            auto [ct, u] = pq.top();
            
            pq.pop();
            
            if (u == n - 1) return ct; 
            
            if (ct > mt[u]) continue;  
            
            for (auto& edge : g[u]) {
               
                int v = edge[0];
                
                long long start = edge[1], end = edge[2];
                
                long long nt = max(ct, start) + 1;
                
                if (nt - 1 > end) continue;  
                
                if (nt < mt[v]) {
                    
                    mt[v] = nt;
                    
                    pq.push({nt, v});
                }
            }
        }
        
        return -1; 
    }
};
