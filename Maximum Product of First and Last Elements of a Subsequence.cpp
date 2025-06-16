class Solution {
public:
    long long maximumProduct(vector<int>& nums, int m) {
        
        long long maxi=INT_MIN;
        long long mini=INT_MAX;
        long long ans=LLONG_MIN;

        for(int i=0;i<nums.size();i++){
            if(i+1>=m){
                mini=min(mini,1LL*nums[i+1-m]);
                maxi=max(maxi,1LL*nums[i+1-m]);

                ans=max({ans,mini*nums[i],maxi*nums[i]});
            }
        }

        return ans;


    }
};
