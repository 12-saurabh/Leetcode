class Solution {
public:
    bool solve(vector<vector<int>>&grid){
        int m=grid.size();
        int n=grid[0].size();

        long long bottom=0;
        long long top=0;

        vector<int>bottomfreq(100001,0);
        vector<int>topfreq(100001,0);

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                bottom+=grid[i][j];
                bottomfreq[grid[i][j]]++;
            }
        }
        for(int i=0;i<m-1;i++){
            for(int j=0;j<n;j++){
                bottom-=grid[i][j];
                bottomfreq[grid[i][j]]--;
                top+=grid[i][j];
                topfreq[grid[i][j]]++;

            }

            if(top==bottom){
                return true;
            }

            long long difftop=top-bottom;

            if(difftop>0 && difftop<=100000){
                int h=i+1;
                int w=n;

                if(h>1 && w>1){
                    if(topfreq[difftop]){
                        return true;
                    }
                }
                else if(h>1 && w==1){
                    if(grid[0][0]==difftop || grid[i][0]==difftop){
                        return true;
                    }
                }
                else if(h==1 && w>1){
                    if(grid[0][0]==difftop || grid[0][w-1]==difftop){
                        return true;
                    }
                }
            }

            long long diffbot=bottom-top;
            if(diffbot>0 && diffbot<=100000){
                int h=m-i-1;
                int w=n;

                if(h>1 && w>1){
                    if(bottomfreq[diffbot]){
                        return true;
                    }
                }
                else if(h>1 && w==1){
                    if(grid[i+1][0]==diffbot || grid[m-1][0]==diffbot){
                        return true;
                    }
                }
                else if(h==1 && w>1){
                    if(grid[m-1][0]==diffbot || grid[m-1][w-1]==diffbot){
                        return true;
                    }
                }
            }
            
        }

        return false;
    }
    bool canPartitionGrid(vector<vector<int>>& grid) {

        if(solve(grid)){
            return true;
        }

        int m=grid.size();
        int n=grid[0].size();

        vector<vector<int>>mat(n,vector<int>(m));

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                mat[j][i]=grid[i][j];
            }
        }

        return solve(mat);




        
    }
};
