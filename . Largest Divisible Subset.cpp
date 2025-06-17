class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {

        int n=nums.size();

        sort(nums.begin(),nums.end());

        vector<int>dp(n,1),hash(n);

        int lastIndex=0;
        int maxi=1;

        for(int ind=0;ind<n;ind++){
            hash[ind]=ind;
            for(int prev_ind=0;prev_ind<ind;prev_ind++){
                if(nums[ind]%nums[prev_ind]==0  && 1+dp[prev_ind]>dp[ind]){
                    dp[ind]=1+dp[prev_ind];
                    hash[ind]=prev_ind;
                }

            }

            if(dp[ind]>maxi){
                maxi=dp[ind];
                lastIndex=ind;
            }
        }

        vector<int>temp;

        temp.push_back(nums[lastIndex]);
        while(hash[lastIndex]!=lastIndex){
            lastIndex=hash[lastIndex];
            temp.push_back(nums[lastIndex]);

        }

        reverse(temp.begin(),temp.end());

        return temp;


        
    }
};
