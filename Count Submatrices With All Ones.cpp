class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        
        int m=mat.size();
        int n=mat[0].size();

        vector<int>height(n,0);
        int ans=0;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==0){
                    height[j]=0;
                }
                else{
                    height[j]+=1;
                }
            }

            for(int j=0;j<n;j++){
                int mini=height[j];

                for(int k=j;k>=0 && mini>0;k--){
                    mini=min(mini,height[k]);
                    ans+=mini;
                }
            }
        }

        return ans;
    

    }
};
