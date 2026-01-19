class Solution {
public:
    bool isValid(vector<vector<int>>&preffix,int mid,int threshold){
        int n=preffix.size();
        int m=preffix[0].size();

        for(int i=mid-1;i<n;i++){
            for(int j=mid-1;j<m;j++){
                int x1=i-mid+1;
                int y1=j-mid+1;

                int sum=preffix[i][j];

                if(x1>0){
                    sum-=preffix[x1-1][j];
                }
                if(y1>0){
                    sum-=preffix[i][y1-1];
                }
                if(x1>0 && y1>0){
                    sum+=preffix[x1-1][y1-1];
                }
                else{
                    sum-=0;
                }

                if(sum<=threshold){
                    return true;
                }

            }
        }

        return false;

    }
    int maxSideLength(vector<vector<int>>& mat, int threshold) {

        int m=mat.size();
        int n=mat[0].size();

        vector<vector<int>>preffix=mat;

        for(int i=0;i<m;i++){
            for(int j=1;j<n;j++){
                preffix[i][j]+=preffix[i][j-1];
            }
        }

        for(int j=0;j<n;j++){
            for(int i=1;i<m;i++){
                preffix[i][j]+=preffix[i-1][j];
            }
        }

        int l=1;
        int h=min(n,m);

        int ans=0;

        while(l<=h){
            int mid=(l+h)/2;

            if(isValid(preffix,mid,threshold)){
                ans=mid;
                l=mid+1;

            }
            else{
                h=mid-1;
            }
        }

        return ans;


        


    }
};
