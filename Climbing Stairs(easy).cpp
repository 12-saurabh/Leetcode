class Solution {
public:

    int climbStairs(int n) {
        int prev2=1;
        int prev=1;

        for(int i=2;i<=n;i++){
            int ans=prev+prev2;
            prev2=prev;
            prev=ans;
        }
        return prev;
     
    }
};
