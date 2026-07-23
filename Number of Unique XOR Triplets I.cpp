class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        
        int n=nums.size();
        if(n<=2){
            return n;
        }

        int countbit=0;
        while(n){
            countbit++;
            n=n>>1;
        }

        int ans=1<<countbit;

        return ans;


    }
};
