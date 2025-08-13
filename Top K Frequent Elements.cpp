class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        vector<int>ans;

        map<int,int>mp;
        for(auto i:nums){
            mp[i]++;
        }
        
        priority_queue<pair<int,int>>pq;
        for(auto i:mp){
            pq.push({i.second,i.first});
        }

        while(!pq.empty() && k>0){
            pair<int,int>first=pq.top();

            pq.pop();

            ans.push_back(first.second);

            k--;
        }

        return ans;

    }
};
