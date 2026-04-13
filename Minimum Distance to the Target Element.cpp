class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        
        int n=nums.size();

        int i=0;
        int mini=INT_MAX;
        while(i<n){
            if(nums[i]==target){
                mini=min(mini,abs(i-start));
            }
            i++;
        }

        return mini;


    }
};
