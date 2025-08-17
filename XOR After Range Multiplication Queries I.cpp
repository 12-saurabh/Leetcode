class Solution {
public:
    
    int const MOD=1e9+7;
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        
        int n=nums.size();

        for(int i=0;i<queries.size();i++){
            int l=queries[i][0];
            int r=queries[i][1];
            int k=queries[i][2];
            int v=queries[i][3];

            while(l<=r){
                nums[l]=(1ll*nums[l]*v)%MOD;
                l+=k;
            }
        }

        int ans=nums[0];
        for(int i=1;i<n;i++){
            ans^=nums[i];
        }

        return ans;

    }
};
