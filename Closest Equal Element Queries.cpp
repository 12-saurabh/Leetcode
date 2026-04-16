class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n=nums.size();

        unordered_map<int,vector<int>>mp;
        for(int i=0;i<n;i++){
            mp[nums[i]].push_back(i);
        }

        vector<int>ans;

        for(auto q:queries){
            auto &v=mp[nums[q]];
            int s=v.size();

            if(s<=1){
                ans.push_back(-1);
                continue;
            }

            int ind=lower_bound(v.begin(),v.end(),q)-v.begin();
            int prev=v[(ind-1+s)%s];
            int next=v[(ind+1)%s];

            int l=abs(q-prev);
            int r=abs(next-q);

            l=min(l,n-l);
            r=min(r,n-r);

            ans.push_back(min(l,r));

        }
        
        return ans;
    }
};
