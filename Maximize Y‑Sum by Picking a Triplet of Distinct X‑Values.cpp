class Solution {
public:
    int maxSumDistinctTriplet(vector<int>& x, vector<int>& y) {
        int n = x.size();
        unordered_map<int, int> mp;

        for (int i = 0; i < n; ++i) {
            if (mp.count(x[i])) {
                mp[x[i]] = max(mp[x[i]], y[i]);
            } else {
                mp[x[i]] = y[i];
            }
        }

        if (mp.size() < 3) return -1;

        priority_queue<int> pq;
        for (auto i : mp) {
            pq.push(i.second);
        }

        int sum = 0;
        for (int i = 0; i < 3; ++i) {
            sum += pq.top();
            pq.pop();
        }

        return sum;
        
    }
};©leetcode
