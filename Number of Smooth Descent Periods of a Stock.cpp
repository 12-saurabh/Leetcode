class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        
        int n=prices.size();

        long long sum=1;
        long long ans=1;

        for(int i=1;i<n;i++){
            if(prices[i]+1==prices[i-1]){
                ans=ans+1;
            }
            else{
                ans=1;
            }
            sum+=ans;
        }

        return sum;
    }
};
