class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {

        int n=nums.size();

        sort(nums.begin(),nums.end());
        int count=1;
        long long sum=0;
        int l=0;

        
        for(int r=0;r<n;r++){
            sum+=nums[r];

            while((long long)nums[r]*(r-l+1)-sum>k){
                sum-=nums[l];
                l++;
            }

            count=max(count,r-l+1);

        }

        return count;



        




        

    }
};
