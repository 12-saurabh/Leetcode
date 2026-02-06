class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());

        int n=nums.size();

        int l=0;
        int maxi=0;

        for(int r=0;r<n;r++){
            while(nums[r]>1ll*nums[l]*k){
                l++;
            }

            maxi=max(maxi,r-l+1);
        }

        return n-maxi;





        
    }
};
