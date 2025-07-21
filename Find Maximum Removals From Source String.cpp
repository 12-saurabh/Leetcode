class Solution {
public:

    int n,m,o;
    int f(int i,int j,int k,string &source,string &pattern,vector<int>&targetIndices,vector<vector<int>>&dp ){

        if(j==m){
            return o-k;
        }

        if(i>=n){
            return -1e6;
        }

        while(i<n && j<m){
            if(k<o && i==targetIndices[k]){
                break;
            }

            if(source[i]==pattern[j]){
                i++;
                j++;
            }
            else{
                i++;
            }
        }


        if(k==o){
            if(j==m){
                return 0;
            }
            else{
                return -1e6;
            }
        }


        if(dp[i][j]!=-1){
            return dp[i][j];
        }

        int skip=1+f(i+1,j,k+1,source,pattern,targetIndices,dp);

        int notskip=f(i,j,k+1,source,pattern,targetIndices,dp);

        return dp[i][j]=max(skip,notskip);

    }
    int maxRemovals(string source, string pattern, vector<int>& targetIndices) {
        
         n=source.size();
         m=pattern.size();
         o=targetIndices.size();

        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));

        return f(0,0,0,source,pattern,targetIndices,dp);


    }
};
