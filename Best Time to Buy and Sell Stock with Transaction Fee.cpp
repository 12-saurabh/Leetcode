class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();

        vector<int>ahead(2,0),curr(2,0);


        for(int ind=n-1;ind>=0;ind--){
            for(int buy=0;buy<=1;buy++){

                int profit=0;
                if(buy){
                    profit=max(-prices[ind]-fee+ahead[0],0+ahead[1]);
                }
                else{
                    profit=max(prices[ind]+ahead[1],0+ahead[0]);
                }

                curr[buy]=profit;
            }
            ahead=curr;
        }

        return ahead[1];
        
    }
};
