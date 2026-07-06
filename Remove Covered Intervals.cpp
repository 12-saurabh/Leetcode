class Solution {
public:
    static bool comp(vector<int>&a,vector<int>&b){
        if(a[0]==b[0]){
            return a[1]>b[1];
        }

        return a[0]<b[0];
    }
    int removeCoveredIntervals(vector<vector<int>>& intervals) {

        sort(intervals.begin(),intervals.end(),comp);

        int ans=intervals.size();
        int maxi=0;

        for(auto v:intervals){
            if(v[1]<=maxi){
                ans--;
            }
            else{
                maxi=v[1];
            }
        }

        return ans;

        
        
    }
};
