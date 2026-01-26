class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        vector<vector<int>>ans;

        sort(arr.begin(),arr.end());

        int mini=INT_MAX;

        for(int i=1;i<arr.size();i++){
            int d=arr[i]-arr[i-1];
            
            if(d<mini){
                mini=d;
                ans.clear();
                ans.push_back({arr[i-1],arr[i]});
            }
            else if(d==mini){
                ans.push_back({arr[i-1],arr[i]});
            }


        }

        return ans;
        
    }
};
