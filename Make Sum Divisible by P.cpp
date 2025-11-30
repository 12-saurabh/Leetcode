class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        
        long long suffix=0;

        for(auto i:nums){
            suffix+=i;
        }

        long long preffix=0;
        int n=nums.size();
        int ans=n;

        unordered_map<int,int>mp;

        mp[0]=-1;

        for(int i=0;i<n;i++){
            preffix+=nums[i];
            suffix-=nums[i];

            mp[preffix%p]=i;

            int remainder=(p-suffix%p)%p;

            if(mp.find(remainder)!=mp.end()){
                ans=min(ans,i-mp[remainder]);
            }
        }

        if(ans==n){
            return -1;
        }
        else{
            return ans;
        }


    }
};
