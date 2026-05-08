class Solution {
public:

    int minJumps(vector<int>& nums) {
        int n=nums.size();

        int maxi=*max_element(nums.begin(),nums.end());

        vector<bool>prime(maxi+1,true);
        prime[0]=false;
        prime[1]=false;

        for(int i=2;i<=maxi;i++){
            if(prime[i]){
                for(long long j=1ll*i*i;j<=maxi;j+=i){
                    prime[j]=false;
                }
            }
        }

        unordered_map<int,vector<int>>mp;
        for(int i=0;i<n;i++){
            mp[nums[i]].push_back(i);
        }


        queue<int>q;
        vector<int>vis(n,0);
        q.push(0);
        vis[0]=1;

        int ans=0;

        while(!q.empty()){
            int s=q.size();

            while(s--){
                int ind=q.front();
                q.pop();

                if(ind==n-1){
                    return ans;
                }

                if(ind>0 && !vis[ind-1]){
                    vis[ind-1]=1;
                    q.push(ind-1);
                }

                if(ind+1<n && !vis[ind+1]){
                    vis[ind+1]=1;
                    q.push(ind+1);
                }

                if(prime[nums[ind]]){
                    int num=nums[ind];
                    for(int i=num;i<=maxi;i+=num){
                        for(int j:mp[i]){
                            if(!vis[j]){
                                q.push(j);
                                vis[j]=1;
                            }
                        }

                        mp[i].clear();
                    }

                    prime[num]=false;
                }
            }
            ans++;
        }

        return -1;



        
        

        
    }
};
