class Solution {
public:
    int rev(int n){
        int ans=0;
        while(n>0){
            int d=n%10;
            ans=ans*10+d;
            n/=10;
        }

        return ans;
    }
    int mirrorDistance(int n) {
        return abs(n-rev(n));
    }
};
