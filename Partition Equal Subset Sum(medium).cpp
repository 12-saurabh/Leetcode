class Solution {
public:
    
    bool canPartition(vector<int>& nums) {
        int n=nums.size();

        int totalsum=0;
        for(int i=0;i<n;i++){
            totalsum+=nums[i];
        }

        if(totalsum%2==1){
            return false;
        }
        else{
            int k=totalsum/2;

            vector<int>prev(k+1,false);

            for(int i=0;i<n;i++){
                prev[0]=true;
            }

            if(nums[0]<=k){
                prev[nums[0]]=true;
            }

            for(int ind=1;ind<n;ind++){
                 vector<int>curr(k+1,false);
                for(int target=1;target<=k;target++){
                    bool nottake=prev[target];
                    bool take=false;

                    if(nums[ind]<=target){
                        take=prev[target-nums[ind]];
                    }

                    curr[target]=nottake || take;
                }
                prev=curr;
            }
            return prev[k];  
        }
        
    }
};
