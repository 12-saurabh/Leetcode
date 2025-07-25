class Solution {
public:
    int maxSum(vector<int>& nums) {

        int n=nums.size();

        bool negat=1;
        int maxi=INT_MIN;
        for(int i:nums){
            if(i>=0){
                negat=0;
            }
            if(i>maxi){
                maxi=i;
            }
        }

        if(negat){
            return maxi;
        }

        set<int>st;
        for(int i=0;i<n;i++){
            st.insert(nums[i]);
        }

        int sum=0;
        for(auto i:st){
            if(i<0){
                continue;
            }
            else{
                sum+=i;
            }
        }

        return sum;

        
    }
};
