class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {

        int n=nums.size();

        unordered_map<int,int>mp;

        for(int i=0;i<n;i++){
            
            int r=(nums[i]%value+value)%value;
            mp[r]++;

        }

        int mex=0;
        while(true){
            int rem=mex%value;
            if(mp[rem]>0){
                mp[rem]--;
                mex++;
            }
            else{
                break;
            }
        }

        return mex;
        
    }
};
