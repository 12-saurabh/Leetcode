
class Solution {
public:
    bool possible(string &s1, string &s2) {
        if (s1.size() != s2.size() + 1) return false;

        int first = 0, second = 0;

        while (first < s1.size()) {
            if (second < s2.size() && s1[first] == s2[second]) {
                first++;
                second++;
            } else {
                first++;
            }
        }

        return first == s1.size() && second == s2.size();
    }

    int longestStrChain(vector<string>& words) {
        int n = words.size();

        sort(words.begin(), words.end(), [](string &s1, string &s2) {
            return s1.size() < s2.size();
        });

        int maxi = 1;
        vector<int> dp(n, 1);

        for (int ind = 0; ind < n; ind++) {
            for (int prev = 0; prev < ind; prev++) {
                if (possible(words[ind], words[prev]) && dp[prev] + 1 > dp[ind]) {
                    dp[ind] = dp[prev] + 1;
                }
            }
            maxi = max(maxi, dp[ind]);
        }

        return maxi;
    }
};
