class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        
        vector<int>v=arr;
        sort(v.begin(),v.end());

        unordered_map<int,int>rank;
        
        int r=1;
        for(int x:v){
            if(!rank.count(x)){
                rank[x]=r;

                r++;
            }
        }
        vector<int>ans;
        for(int x:arr){
            ans.push_back(rank[x]);
        }
        return ans;
    }
};
