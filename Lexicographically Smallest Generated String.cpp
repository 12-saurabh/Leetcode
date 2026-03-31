class Solution {
public:
    string generateString(string str1, string str2) {
        
        int n=str1.size();
        int m=str2.size();

        string ans(n+m-1,'a');
        vector<int>vis(n+m-1,0);

        for(int i=0;i<n;i++){
            if(str1[i]=='T'){
                for(int j=i;j<i+m;j++){
                    if(vis[j] && ans[j]!=str2[j-i]){
                        return "";
                    }
                    else{
                        ans[j]=str2[j-i];
                        vis[j]=1;
                    }
                }
            }
        }

        for(int i=0;i<n;i++){
            if(str1[i]=='F'){
                bool flag=false;
                int ind=-1;

                for(int j=i+m-1;j>=i;j--){
                    if(str2[j-i]!=ans[j]){
                        flag=true;
                    }
                    if(ind==-1 && !vis[j]){
                        ind=j;
                    }
                }
                if(flag){
                    continue;
                }
                else if(ind!=-1){
                    ans[ind]='b';
                }
                else{
                    return "";
                }
            }
        }

        return ans;
    }
};
