class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        int n=nums.size();
        int i=0;
        while(i<n){
            int sum=0;
            while(nums[i]>0){
                int d=nums[i]%10;
                sum+=d;
                nums[i]/=10;     
            }

            if(sum==i){
                return i;
            }
            i++;
            
        }
        return -1;
    
        
    }
};
