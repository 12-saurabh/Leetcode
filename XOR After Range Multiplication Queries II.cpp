class Solution {
public:
    const int MOD=1e9+7;
    int power(long long base,long long exp){
        long long  ans=1;
        while(exp>0){
            if(exp&1){
                ans=(ans*base)%MOD;
            }

            base=(base*base)%MOD;
            exp>>=1;
        }

        return ans;

    }
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();

        int blocksize=ceil(sqrt(n));

        unordered_map<int,vector<vector<int>>>mp;

        for(auto &query:queries){
            int L=query[0];
            int R=query[1];
            int K=query[2];
            int V=query[3];

            if(K>=blocksize){
                for(int i=L;i<=R;i+=K){
                    nums[i]=(1ll*nums[i]*V)%MOD;
                }
            }
            else{
                mp[K].push_back(query);
            }
        }

        for(auto &[K,allquery]:mp){
            vector<long long>diff(n,1);

            for(auto &query:allquery){
                int L=query[0];
                int R=query[1];
                int V=query[3];

                diff[L]=(1ll*diff[L]*V)%MOD;

                int steps=(R-L)/K;
                int next=L+(steps+1)*K;

                if(next<n){
                    diff[next]=(1ll*diff[next]*power(V,MOD-2))%MOD;
                }
            }

            for(int i=0;i<n;i++){
                if(i-K>=0){
                    diff[i]=(1ll*diff[i]*diff[i-K])%MOD;
                }
            }

            for(int i=0;i<n;i++){
                nums[i]=(1ll*nums[i]*diff[i])%MOD;
            }
        }

        int ans=0;
        for(int i=0;i<n;i++){
            ans^=nums[i];
        }

        return ans;

    }
};
