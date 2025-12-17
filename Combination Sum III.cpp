class Solution {
private:
    
    void rec(int i,vector<int>&nums,vector<int>&curr,vector<vector<int>>&ans,int k,int target){
        int n=nums.size();

        if(curr.size()==k && target==0){
            ans.push_back(curr);
            return;
        }

        if(target<0 || i==n){
            return;
        }

        curr.push_back(nums[i]);
        rec(i+1,nums,curr,ans,k,target-nums[i]);
        curr.pop_back();

        rec(i+1,nums,curr,ans,k,target);
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {

        vector<int>nums={1,2,3,4,5,6,7,8,9};

        vector<vector<int>>ans;
        vector<int>curr;

        rec(0,nums,curr,ans,k,n);

        return ans;



        
    }
};
