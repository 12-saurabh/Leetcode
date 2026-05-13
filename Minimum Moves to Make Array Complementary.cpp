class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {

        int n=nums.size();

        vector<int>diff(2*limit+2,0);
        
        for(int i=0;i<n/2;i++){
            int a=nums[i];
            int b=nums[n-1-i];

            int l=min(a,b)+1;
            int h=max(a,b)+limit;

            int sum=a+b;

            diff[2]+=2;
            diff[2*limit+1]-=2;

            diff[l]-=1;
            diff[h+1]+=1;

            diff[sum]-=1;
            diff[sum+1]+=1;

        }

        int ans=INT_MAX;
        int m=0;

        for(int t=2;t<=2*limit;t++){
            m+=diff[t];
            ans=min(ans,m);
        }

        return ans;


        
    }
};
