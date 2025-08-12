class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {

        if(hand.size()%groupSize!=0){
            return false;
        }
        map<int,int>mp;

        for(auto i:hand){
            mp[i]++;
        }

        priority_queue<int,vector<int>,greater<int>>pq;
        for(auto i:mp){
            pq.push(i.first);
        }

        while(!pq.empty()){
            int start=pq.top();

            for(int i=0;i<groupSize;i++){
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
