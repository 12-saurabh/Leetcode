class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {

        int n=nums.size();

        long long prefix=0;
        long long sub=LLONG_MIN;

        vector<long long>v(k,LLONG_MAX/4);
        v[(k-1)%k]=0;

        for(int i=0;i<n;i++){
            prefix+=nums[i];
            sub=max(sub,prefix-v[i%k]);
            v[i%k]=min(v[i%k],prefix);
        }

        return sub;



        


        
    }
};
