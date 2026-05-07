class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {
        int n=nums.size();

        vector<int>preffix(n);
        vector<int>suffix(n);

        vector<int>ans(n);

        preffix[0]=nums[0];
        suffix[n-1]=nums[n-1];

        for(int i=1;i<n;i++){
            preffix[i]=max(preffix[i-1],nums[i]);
            suffix[n-i-1]=min(suffix[n-i],nums[n-i-1]);
        }

        ans[n-1]=preffix[n-1];
        for(int i=n-2;i>=0;i--){

            if(preffix[i]>suffix[i+1]){
                ans[i]=ans[i+1];

            }
            else{
                ans[i]=preffix[i];
            }
        }
        

        return ans;
    }
};
