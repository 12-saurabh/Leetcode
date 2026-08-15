class Solution {
public:
    int longestSubsequence(vector<int>& nums) {

        int n=nums.size();

        int ans=0;
        bool f=false;

        for(int i=0;i<n;i++){
            ans^=nums[i];

            if(ans!=0){
                f=true;
            }
        }        

        if(!f){
            return 0;
        }

        if(ans!=0){
            return n;
        }


        return n-1;


    }
};
