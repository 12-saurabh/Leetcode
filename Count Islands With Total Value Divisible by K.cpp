
class Solution {
public:
    int countIslands(vector<vector<int>>& grid, int k) {
        
        int row = grid.size();
        
        int col = grid[0].size();

        // here v is working as a marker for visisted number or unvisited number
        vector<vector<bool>> v(row, vector<bool>(col, false));
        
        int c = 0;

        // for directions 
        int x[4] = {-1, 1, 0, 0};
        int y[4] = {0, 0, -1, 1};

        for (int i = 0; i < row; ++i) {
            
            for (int j = 0; j < col; ++j) {
                
                if (grid[i][j] > 0 && !v[i][j]) {
                    
                    long long ans = 0;

                    queue<pair<int, int>> q;
                    
                    q.push(make_pair(i, j));
                    
                    v[i][j] = true;

                    while (!q.empty()) {
                        
                        int xx = q.front().first;
                        
                        int yy = q.front().second;
                        
                        q.pop();

                        ans += grid[xx][yy];

                        for (int d = 0; d < 4; ++d) {
                            
                            int xdir = xx + x[d];
                            int ydir = yy + y[d];

                            if (xdir >= 0 && xdir < row && ydir >= 0 && ydir < col &&
                                
                                grid[xdir][ydir] > 0 && !v[xdir][ydir]) {
                                
                                v[xdir][ydir] = true;
                                
                                q.push(make_pair(xdir, ydir));
                            }
                        }
                    }

                    if (ans % k == 0){
                        c++;
                    }
                }
            }
        }

        return c;
    }
};
