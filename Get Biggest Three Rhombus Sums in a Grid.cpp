class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {

        int m=grid.size();
        int n=grid[0].size();

        set<int,greater<int>>st;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){

                st.insert(grid[i][j]);

                for(int k=1; ;k++){
                    int bottom=i+2*k;
                    int left=j-k;
                    int right=j+k;

                    if(bottom>=m || left<0 || right>=n){
                        break;
                    }

                    int x=i;
                    int y=j;

                    int sum=0;

                    for(int t=0;t<k;t++){
                        sum+=grid[x+t][y+t];
                    }

                    for(int t=0;t<k;t++){
                        sum+=grid[x+k+t][y+k-t];
                    }

                    for(int t=0;t<k;t++){
                        sum+=grid[x+2*k-t][y-t];
                    }

                    for(int t=0;t<k;t++){
                        sum+=grid[x+k-t][y-k+t];
                    }


                    st.insert(sum);
                }
            }
        }

        vector<int>ans;

        for(auto i:st){
            ans.push_back(i);

            if(ans.size()==3){
                break;
            }
        }

        return ans;

        
    }
};
