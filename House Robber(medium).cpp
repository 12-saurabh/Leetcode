class Solution {
public:

    int f(int ind,vector<int>&nums){
        int prev=nums[0];
        int prev2=0;

        for(int i=1;i<ind;i++){
            int include=nums[i];
            if(i>1){
                include+=prev2;
            }

            int exclude=prev;

            int curr=max(include,exclude);

            prev2=prev;
            prev=curr;
        }
        return prev;


    }
    int rob(vector<int>& nums) {

        int n=nums.size();
        int ans=f(n,nums);
        return ans;
        
    }
};
