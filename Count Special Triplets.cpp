class Solution {
public:
    const int MOD=1e9+7;
    int specialTriplets(vector<int>& nums) {
        
        int n=nums.size();

        long long ans=0;

        unordered_map<int,int>right,left;

        for(int i=0;i<n;i++){
            right[nums[i]]++;
        }

        for(int j=0;j<n;j++){
            right[nums[j]]--;

            int t=nums[j]*2;

            long long l=left[t];
            long long r=right[t];

            ans=(ans+(l*r)%MOD)%MOD;

            left[nums[j]]++;
        }


        return ans;

        
    }
};
