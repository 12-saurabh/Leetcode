class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        
        int n=nums.size();

        vector<long long>preffix(2*n+1,0);
        preffix[n]=1;

        int count=n;
        long long preffixsum=0;
        long long ans=0;

        for(int i:nums){
            if(i==target){
                preffixsum+=preffix[count];
                count++;
                preffix[count]++;
            }
            else{
                count--;
                preffixsum-=preffix[count];
                preffix[count]++;
            }

            ans+=preffixsum;
        } 

        return ans;


    }
};
