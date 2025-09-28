class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        
        int n=nums.size();

        sort(nums.begin(),nums.end());
        int ans=0;

        for(int i=1;i<n-1;i++){
            int a=nums[i-1];
            int b=nums[i];
            int c=nums[i+1];

            if(a+b>c){
                ans=max(ans,(a+b+c));
            }
        }

        return ans;
    }
};
