class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {

        int n=nums.size();

        unordered_map<int,int>mp;

        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }

        int maxi=0;
        for(auto i:mp){
            maxi=max(maxi,i.second);
        }

        int ans=0;
        for(auto i:mp){
            if(maxi==i.second){
                ans+=maxi;
            }
        }

        return ans;


        
    }
};
