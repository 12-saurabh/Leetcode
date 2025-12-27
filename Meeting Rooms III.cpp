class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {

        sort(meetings.begin(),meetings.end());
        vector<int>count(n);
        vector<long long>timer(n);

        int i=0;
        while(i<meetings.size()){
            int s=meetings[i][0];
            int e=meetings[i][1];

            long long d=e-s;

            int room=-1;
            long long earl=LLONG_MAX;
            int earlroom=-1;

            for(int j=0;j<n;j++){
                if(timer[j]<earl){
                    earl=timer[j];
                    earlroom=j;

                }
                if(timer[j]<=s){
                    room=j;
                    break;
                }
            }

            if(room!=-1){
                timer[room]=e;
                count[room]++;
            }
            else{
                timer[earlroom]+=d;
                count[earlroom]++;
            }

            i++;
        }

        int max=0;
        int ind=0;
        for(int x=0;x<n;x++){
            if(count[x]>max){
                max=count[x];
                ind=x;
            }
        }
        
        return ind;
    }
};
