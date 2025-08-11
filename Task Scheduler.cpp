
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        map<char,int> mp;
        for (auto t : tasks) mp[t]++;

        priority_queue<pair<int,char>> pq;
        
        for (auto &p : mp) pq.push({p.second, p.first});

        vector<char> v;

        while (!pq.empty()) {
            vector<pair<int,char>> temp;
           
           
            int cycleLen = n + 1;        

            for (int i = 0; i < cycleLen; i++) {
                if (!pq.empty()) {
                   
                    auto task = pq.top();
                   
                    pq.pop();
                    
                    v.push_back(task.second);
                    
                    task.first--;
                    
                    if (task.first > 0) temp.push_back(task);
                }
                else {
                    
                    if (!temp.empty()) v.push_back(' ');
                    
                    else break; 
                }
            }

            for (auto &x : temp) pq.push(x); 
        }

        return v.size();
    }
};
