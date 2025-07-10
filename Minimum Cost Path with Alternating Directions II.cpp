
class Solution {
public:
    long long minCost(int m, int n, vector<vector<int>>& waitCost) {
        
        vector<vector<long long>> oddTime(m, vector<long long>(n, LLONG_MAX));
        vector<vector<long long>> evenTime(m, vector<long long>(n, LLONG_MAX));
        
        priority_queue<tuple<long long, int, int, bool>, 
                       vector<tuple<long long, int, int, bool>>, 
                       greater<>> pq;
        
        long long sc = 1LL * (0 + 1) * (0 + 1);
        
        oddTime[0][0] = sc;
        
        pq.push({sc, 0, 0, true});
        
        int dx[] = {0, 1};
        int dy[] = {1, 0};
        
        while (!pq.empty()) {
            
            auto [cost, x, y, isOdd] = pq.top();
            
            pq.pop();
            
            if (x == m - 1 && y == n - 1) {
                return cost;
            }
            
            if (isOdd) { 
                for (int dir = 0; dir < 2; dir++) {
                    int nx = x + dx[dir];
                    int ny = y + dy[dir];
                    
                    if (nx < m && ny < n) {
                        
                        long long nc = cost + 1LL * (nx + 1) * (ny + 1);
                        
                        if (nc < evenTime[nx][ny]) {
                            
                            evenTime[nx][ny] = nc;
                            
                            pq.push({nc, nx, ny, false});
                        }
                    }
                }
            } else { 
                long long nc = cost + waitCost[x][y];
               
                if (nc < oddTime[x][y]) {
                   
                    oddTime[x][y] = nc;
                    
                    pq.push({nc, x, y, true});
                }
            }
        }
        
        return -1; 
    }
};
