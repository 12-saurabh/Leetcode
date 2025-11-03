class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {

        int n=colors.length();

        int ans=0;
        int i=0;
        while(i<n){
            int j=i;
            int sum=0;
            int maxi=0;
            while(j<n && colors[j]==colors[i]){
                sum+=neededTime[j];
                maxi=max(maxi,neededTime[j]);
                j++;
            }
            ans+=(sum-maxi);
            i=j;
        }

        return ans;
        
    }
};
