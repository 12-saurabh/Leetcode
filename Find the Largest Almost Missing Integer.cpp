class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
    int n = nums.size();
    map<int, int> c;

    for (int i = 0; i <= n - k; ++i) {
        map<int, bool> mp;
        for (int j = i; j < i + k; ++j) {
            mp[nums[j]] = true;
        }
        for (auto& p : mp) {
            c[p.first]++;
        }
    }

    int ans = -1;
    for (auto& p : c) {
        if (p.second == 1) {
            ans = max(ans, p.first);
        }
    }

    return ans;
    }
};
