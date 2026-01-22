class Solution {
public:

    int minimumPairRemoval(vector<int>& nums) {
        int count=0;
        while(true){

            bool is_sorted=true;

            for(int i=1;i<nums.size();i++){
                if(nums[i]<nums[i-1]){
                    is_sorted=false;
                }
            }

            if(is_sorted){
                return count;
            }


            int mini=INT_MAX;
            int ind=0;

            for(int i=0;i<nums.size()-1;i++){
                int sum=nums[i]+nums[i+1];
                if(sum<mini){
                    mini=sum;
                    ind=i;
                }
            }

            nums[ind]=mini;
            nums.erase(nums.begin()+ind+1);

            count++;

        }
   
    }
};
