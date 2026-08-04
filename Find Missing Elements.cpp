class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {

        vector<int>ans;
        set<int>st;
        for(auto i:nums){
            st.insert(i);
        }

        int maxi=*max_element(nums.begin(),nums.end());
        int mini=*min_element(nums.begin(),nums.end());

        for(int i=mini;i<=maxi;i++){
            if(!st.contains(i)){
                ans.push_back(i);
            }
        }

        return ans;

        
    }
};
