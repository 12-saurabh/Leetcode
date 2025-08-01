class Solution {
public:
    vector<vector<int>> generate(int numRows) {

        int n=numRows;

        vector<vector<int>>v;

        for(int i=0;i<n;i++){
            vector<int>temp(i+1,1);
            for(int j=1;j<i;j++){
                temp[j]=v[i-1][j]+v[i-1][j-1];
            }
            v.push_back(temp);
        }
        
        return v;
    }
};
