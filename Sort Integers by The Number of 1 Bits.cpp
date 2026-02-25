class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;

        for(int i=0;i<arr.size();i++){
            int x=__builtin_popcount(arr[i]);

            pq.push({x,arr[i]});

        }

        vector<int>ans;
        while(!pq.empty()){
            int i=pq.top().second;

            pq.pop();

            ans.push_back(i);
        }

        return ans;
    }
};
