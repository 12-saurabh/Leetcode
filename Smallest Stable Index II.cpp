class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        
        int n=nums.size();

        int ans=INT_MAX;

        vector<int>maxi(n);
        int maxi_ele=nums[0];
        for(int i=0;i<n;i++){
            maxi_ele=max(maxi_ele,nums[i]);
            maxi[i]=maxi_ele;
        }

        int mini_ele=nums[n-1];
        for(int i=n-1;i>=0;i--){
            mini_ele=min(mini_ele,nums[i]);

            if(abs(maxi[i]-mini_ele)<=k){
                ans=min(ans,i);
            }
        }

        if(ans==INT_MAX){
            return -1;
        }
        else{
            return ans;
        }
    }
};
