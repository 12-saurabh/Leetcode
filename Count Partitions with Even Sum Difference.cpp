class Solution {
public:
    int countPartitions(vector<int>& nums) {

        int ans=0;
        for(auto i:nums){
            ans+=i;
        }

        if(ans%2==0){
            return nums.size()-1;
        }
        return 0;
        
    }
};
