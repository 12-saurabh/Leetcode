class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {

        int n=nums.size();

        int i=1;
        int j=0;

        int l=1;
        int ans=0;
        
        while(i<n){

            if(nums[i]>nums[i-1]){
                l++;
            }
            else{
                j=l;
                l=1;
            }

            ans=max(ans,min(j,l));
            ans=max(ans,l/2);

            i++;
        }

        if(ans>=k){
            return true;
        }
        else{
            return false;
        }


        
    }
};
