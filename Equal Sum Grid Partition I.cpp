class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        
        int m=grid.size();
        int n=grid[0].size();

        long long total=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                total+=grid[i][j];
            }

        }


        for(int i=0;i<m;i++){
            long long sum=0;
            for(int j=0;j<n;j++){
                sum+=grid[i][j];
            }

            hr.push_back(sum);
        }

        for(int j=0;j<n;j++){
            long long sum=0;
            for(int i=0;i<m;i++){
                sum+=grid[i][j];
            }

            vt.push_back(sum);
        }

        long long prefix=0;
        for(int i=0;i<hr.size();i++){
            prefix+=hr[i];

            if(prefix==total-prefix){
                return true;
            }

        }
        prefix=0;
        for(int j=0;j<vt.size();j++){
            prefix+=vt[j];

            if(prefix==total-prefix){
                return true;
            }
        }

        return false;



        











    }
};
