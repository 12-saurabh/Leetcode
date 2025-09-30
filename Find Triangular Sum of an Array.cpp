class Solution {
public:
    int triangularSum(vector<int>& nums) {

        int n=nums.size();

        if(n==1){
            return nums[n-1];
        }

        for(int i=n-1;i>=0;i--){
            vector<int>newnums(i);
            for(int j=0;j<i;j++){
                newnums[j]=(nums[j]+nums[j+1])%10;
            }

            nums=newnums;
        }

        return nums[0];


        
    }
};
