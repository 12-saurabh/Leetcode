class Solution {
public:
    vector<int> minCosts(vector<int>& cost) {
    int n = cost.size();
        
    vector<int> v(n);
    int mini = cost[0];
    v[0] = cost[0];
    
    for (int i = 1; i < n; ++i) {
        mini = min(mini, cost[i]);
        v[i] = mini;
    }
    
    return v;
    }
};
