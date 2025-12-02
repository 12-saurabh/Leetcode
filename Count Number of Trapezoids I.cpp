class Solution {
public:

    const int MOD=1e9+7;
    int countTrapezoids(vector<vector<int>>& points) {

        unordered_map<int,int>mp;

        long long ans=0;
        long long sum=0;

        for(auto i:points){
            mp[i[1]]++;
        }

        for(auto x:mp){
            long long numP=x.second;
            long long edge=1ll*numP*(numP-1)/2;

            ans+=edge*sum;
            sum+=edge;
        }

        return ans%MOD;
        
    }
};
