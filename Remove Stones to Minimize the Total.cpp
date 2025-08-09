class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {

        int n=piles.size();

        priority_queue<int>pq;

        for(int i=0;i<n;i++){
            pq.push(piles[i]);
        }

        while(k--){
            int topelement=pq.top();
            pq.pop();

            topelement=topelement-floor(topelement/2);

            pq.push(topelement);
        }

        int sum=0;
        while(!pq.empty()){
            int top=pq.top();
            sum+=top;
            pq.pop();
        }

        return sum;
        
    }
};
