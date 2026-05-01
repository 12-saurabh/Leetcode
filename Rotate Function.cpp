class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {

        int n=nums.size();

        if(n==1){
            return 0;
        }

        int f=0;
        int sum=0;

        for(int i=0;i<n;i++){
            sum+=nums[i];

            f+=(i*nums[i]);
        }

        int p=f;
        for(int i=n-1;i>=0;i--){
            p=p+sum-(nums[i]*n);
            f=max(f,p);
            
        }

        return f;


    }
};
