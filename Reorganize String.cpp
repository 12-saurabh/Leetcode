
class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char, int> mp;

        for (char c : s) {
            mp[c]++;
        }

        priority_queue<pair<int, char>> pq;
        for (auto &i : mp) {
            pq.push({i.second, i.first});
        }

        string ans = "";

        while (pq.size() > 1) {
            auto first = pq.top();
            pq.pop();
            auto second = pq.top();
            pq.pop();

            ans.push_back(first.second);
            first.first--;

            ans.push_back(second.second);
            second.first--;

            if (first.first > 0) {
                pq.push(first);
            }
            if (second.first > 0) {
                pq.push(second);
            }
        }

        if (!pq.empty()) {
            auto last = pq.top();
            pq.pop();

            if (last.first > 1) {
                return "";
            }
            ans.push_back(last.second);
        }

        return ans;
    }
};
