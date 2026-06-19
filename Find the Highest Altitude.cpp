class Solution {
public:
    int largestAltitude(vector<int>& gain) {

        int n=gain.size();

        int ans=0;
        vector<int>preffix(n+1,0);

        for(int i=1;i<=n;i++){
            preffix[i]=preffix[i-1]+gain[i-1];

            ans=max(ans,preffix[i]);
        }

        return ans;


        

        
    }
};
