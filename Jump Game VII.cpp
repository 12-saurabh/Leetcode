class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {

        int n=s.length();

        vector<int>vis(n,0);

        queue<int>q;
        q.push(0);

        vis[0]=1;

        int maxi=0;
        while(!q.empty()){
            int ind=q.front();
            q.pop();

            if(ind==n-1){
                return true;
            }

            int i=max(ind+minJump,maxi+1);
            int j=min(ind+maxJump,n-1);

            maxi=j;

            for(int k=i;k<=j;k++){
                if(s[k]=='0' && !vis[k]){
                    q.push(k);
                    vis[k]=1;
                }
            }

        }

        return false;
        
        
    }
};
