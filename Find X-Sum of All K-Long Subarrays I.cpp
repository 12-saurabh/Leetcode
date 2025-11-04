class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        
        vector<int>ans;
        int n=nums.size();

        for(int i=0;i<n-k+1;i++){
            unordered_map<int,int>mp;

            for(int j=i;j<i+k;j++){
                mp[nums[j]]++;
            }
            
            vector<pair<int,int>>f;
            for(auto x:mp){
                int k=x.first;
                int v=x.second;

                f.push_back({v,k});
            }

            sort(f.begin(),f.end(),greater<pair<int,int>>());


            int sum=0;

            for(int j=0;j<x && j<f.size();j++){
                sum+=f[j].first*f[j].second;
            }

            ans.push_back(sum);
        }

        return ans;



        
    }
};
