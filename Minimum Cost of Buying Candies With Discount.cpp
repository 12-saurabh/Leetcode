class Solution {
public:
    int minimumCost(vector<int>& cost) {

        sort(cost.begin(),cost.end(),greater<int>());

        int n=cost.size();

        int ans=0;
        int i=0;

        while(i<n){
            if((i+1)%3!=0){
                ans+=cost[i];
            }
            i++;
        }

        return ans;

        
    }
};
