class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {

        if(nums.size()%k!=0){
            return false;
        }
        map<int,int>mp;

        for(auto i:nums){
            mp[i]++;
        }

        priority_queue<int,vector<int>,greater<int>>pq;
        for(auto i:mp){
            pq.push(i.first);
        }

        while(!pq.empty()){
            int start=pq.top();

            for(int i=0;i<k;i++){
                int card=start+i;

                if(mp[card]==0){
                    return false;
                }

                mp[card]--;

                if(mp[card]==0){
                    if(card!=pq.top()){
                        return false;
                    }
                    pq.pop();
                }
            }
        }

        return true;
        
    }
};
