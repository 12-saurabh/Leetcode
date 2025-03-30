class Solution {
public:
    int reverseDegree(string s) {
    int ans = 0;
    for (int i = 0; i < s.size(); ++i) {
        char c = s[i];
        int r = 26 - (c - 'a');
        int id = i + 1; 
        ans += r * id;
    }
    return ans;
    }
};
