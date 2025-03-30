class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
    string x = '1' + s + '1';
        
    int n = x.size();
        
    vector<int> o, z;
    char c = x[0];
    int count = 1;
    
    for (int i = 1; i < n; ++i) {
        if (x[i] == c) {
            count++;
        } else {
            if (c == '1') {
                o.push_back(count);
            } else {
                z.push_back(count);
            }
            c = x[i];
            count = 1;
        }
    }
    if (c == '1') {
        o.push_back(count);
    } else {
        z.push_back(count);
    }
    
    if (z.empty()) {
        return s.size();
    }
    
    int ans = 0;
    for (char i : s) {
        if (i == '1') ans++;
    }
    
    int maxi = ans;
    for (int i = 1; i < o.size() - 1; ++i) {
        int p = z[i-1] + o[i] + z[i];
        int g = p - o[i];
        maxi = max(maxi, ans + g);
    }
    
    return maxi;       
    }
};
