class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(auto i:nums){
            mp[i]++;
        }
        for(auto x:mp){
            if(x.second>=2){
                return x.first;
            }
        }
        return -1;
    }
};
