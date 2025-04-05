class Solution {
public:
    
    int f(int target,vector<int>&coins){

        int n=coins.size();
        vector<int>prev(target+1,0),curr(target+1,0);

        for(int T=0;T<=target;T++){
            if(T%coins[0]==0){
                prev[T]=T/coins[0];
            }
            else{
                prev[T]=1e9;
            }
        }

        for(int ind=1;ind<n;ind++){
            for(int T=0;T<=target;T++){
                int nottake=0+prev[T];

                int take=1e9;
                if(coins[ind]<=T){
                    take=1+curr[T-coins[ind]];
                }

                curr[T]=min(nottake,take);
            }

            prev=curr;
        }

        return prev[target];

    }
    
    int coinChange(vector<int>& coins, int amount) {
        int ans=f(amount,coins);

        if(ans>=1e9){
            return -1;
        }
        else{
            return ans;
        }


        
    }
};
