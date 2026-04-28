class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {

        vector<int>row;

        for(auto &r:grid){
            for(int num:r){
                row.push_back(num);
            }
        }

        int b=row[0];
        for(int i:row){
            if(abs(i-b)%x!=0){
                return -1;
            }
        }

        sort(row.begin(),row.end());

        int med=row[row.size()/2];

        int ans=0;
        for(int i:row){
            ans+=abs(i-med)/x;
        }

        return ans;
        
    }
};
