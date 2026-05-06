class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {

        int n=boxGrid.size();
        int m=boxGrid[0].size();

        vector<vector<char>>ans(m,vector<char>(n,'.'));

        for(int i=0;i<n;i++){

            int l=m-1;
            for(int j=m-1;j>=0;j--){
                if(boxGrid[i][j]=='*'){
                    ans[j][n-i-1]='*';
                    l=j-1;
                }
                else if(boxGrid[i][j]=='#'){
                    ans[l][n-i-1]='#';
                    l--;
                }
            }
        }

        return ans;
        
    }
};
