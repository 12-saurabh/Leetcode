class Solution {
public:
    int minOperations(vector<int>& nums) {

        int n=nums.size();

        for(int i=1;i<n;i++){
            if(nums[i]!=nums[0]){
                return 1;
            }
        }

        return 0;


        int target=nums[0];
        for(int i=1;i<n;i++){
            target&=nums[i];
        }


        int count=0;
        int ans=-1;

        for(int i=0;i<n;i++){
            ans&=nums[i];

            if(ans==target){
                count++;
                ans=-1;
            }
        }


        return count;
        

        
    }
};
