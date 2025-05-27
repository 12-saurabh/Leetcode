
class Solution {
public:
    int maxSubstrings(const string& word) {
        int n = (int)word.size();
        vector<vector<int>> positions(26);
        
        for (int i = 0; i < n; ++i) {
            positions[word[i] - 'a'].push_back(i);
        }
        
        vector<pair<int,int>> intervals;
        
        for (int c = 0; c < 26; ++c) {
            const auto& pos = positions[c];
            int m = (int)pos.size();
            if (m < 2) continue;
            
            int j = 0;
            for (int i = 0; i < m; ++i) {
                while (j < m && pos[j] - pos[i] + 1 < 4) j++;
                if (j < m) {
                    intervals.emplace_back(pos[i], pos[j]);
                }
            }
        }
        
        sort(intervals.begin(), intervals.end(), [](const pair<int,int>& a, const pair<int,int>& b) {
            return a.second < b.second;
        });
        
        int count = 0;
        int lastEnd = -1;
        for (auto& [start, end] : intervals) {
            if (start > lastEnd) {
                count++;
                lastEnd = end;
            }
        }
        
        return count;
    }
};
