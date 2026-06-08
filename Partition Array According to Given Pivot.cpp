class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        
        int n=nums.size();

        vector<int>ans;

        for(auto i:nums){
            if(i<pivot){
                ans.push_back(i);
            }

        }

        for(auto i:nums){
            if(i==pivot){
                ans.push_back(i);
            }
        }

        for(auto i:nums){
            if(i>pivot){
                ans.push_back(i);
            }
        }

        return ans;
    }
};
