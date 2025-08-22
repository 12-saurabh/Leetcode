class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        
        int n=grid.size();
        int m=grid[0].size();

        int left=INT_MAX;
        int right=INT_MIN;
        int top=INT_MAX;
        int bottom=INT_MIN;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){

                if(grid[i][j]==1){
                    left=min(left,i);
                    right=max(right,i);
                    top=min(top,j);
                    bottom=max(bottom,j);
                }
            }
        }

        int height=right-left+1;
        int width=bottom-top+1;

        return height*width;






    }
};
