class Solution {
public:

    int sum(int n){
        int s=0;
        while(n>0){
            int d=n%10;
            s+=d;
            n/=10;
        }
        return s;
    }
    int minSwaps(vector<int>& nums) {
        int n=nums.size();

        vector<pair<pair<int,int>,int>>v;
        for(int i=0;i<n;i++){
            int s=sum(nums[i]);
            v.push_back({{s,nums[i]},i});
        }

        sort(v.begin(),v.end());

        int swapcount=0;
        
        vector<bool>visited(n,false);

        for(int i=0;i<n;i++){
            if(visited[i] || v[i].second==i){
                continue;
            }

            int size=0;
            int j=i;

            while(!visited[j]){
                visited[j]=1;
                size++;
                j=v[j].second;
            }
            if(size>1){
                swapcount+=(size-1);
            }
        }

        return swapcount;
               
    }
};
