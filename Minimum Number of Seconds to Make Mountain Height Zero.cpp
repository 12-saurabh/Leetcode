class Solution {
public:
    
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        
        priority_queue<vector<long long>,vector<vector<long long>>,greater<vector<long long>>>pq;

        for(auto i:workerTimes){
            pq.push({i,i,1});
        }

        long long ans=0;
        long long currh=mountainHeight;

        while(!pq.empty()){
            auto i=pq.top();
            pq.pop();

            long long maxT=i[0];
            long long baseT=i[1];
            long long reduced=i[2];

            ans=max(ans,maxT);
            currh--;

            if(currh==0){
                break;
            }

            long long nexth=reduced+1;
            long long totalT=(baseT*(nexth)*(nexth+1))/2;

            pq.push({totalT,baseT,nexth});
        }

        return ans;
    }
};
