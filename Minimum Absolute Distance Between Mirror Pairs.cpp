class Solution {
public:
    int reverse(int n){
        int ans=0;
        while(n>0){
            int d=n%10;
            ans=ans*10+d;
            n/=10;
        }

        return ans;
    }
    int minMirrorPairDistance(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>mp;

        int ans=INT_MAX;

        for(int i=0;i<n;i++){
            if(mp.count(nums[i])){
                ans=min(ans,i-mp[nums[i]]);
            }

            int x=reverse(nums[i]);

            mp[x]=i;
        }

        if(ans==INT_MAX){
            return -1;
        }
        else{
            return ans;
        }
    }
};
