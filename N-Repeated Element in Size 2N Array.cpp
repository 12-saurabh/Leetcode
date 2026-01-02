class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {

        int n=nums.size();

        unordered_map<int,int>mp;
        for(auto i:nums){
            mp[i]++;
        }

        for(auto x:mp){
            if(x.second==n/2){
                return x.first;
            }
        }
        return -1;
        
    }
};
