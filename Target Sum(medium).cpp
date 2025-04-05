class Solution {
public:

    int f(int target,vector<int>&nums){
        
        int n=nums.size();

        vector<int>prev(target+1,0),curr(target+1,0);


        if(nums[0]==0){
            prev[0]=2;
        }

        else{
            prev[0]=1;
        }

        if(nums[0]!=0 && nums[0]<=target){
            prev[nums[0]]=1;
        }

        for(int ind=1;ind<n;ind++){
            for(int tar=0;tar<=target;tar++){
                int nottake=prev[tar];

                int take=0;
                if(nums[ind]<=tar){
                    take=prev[tar-nums[ind]];
                }

                curr[tar]=nottake+take;

            }
            prev=curr;
        }

        return prev[target];

    }

    int findTargetSumWays(vector<int>& nums, int d) {

        int n=nums.size();

        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }

        if(sum-d<0 || (sum-d)%2){
            return 0;
        }

        int target=(sum-d)/2;



        int ans=f(target,nums);
        return ans;

        
        
    }
};
