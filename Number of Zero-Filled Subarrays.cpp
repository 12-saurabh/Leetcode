class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        
        int  zerolength=0;
        long long  answer=0;

        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                zerolength++;
            }
            else if(zerolength){
                answer+=(long long)zerolength*(zerolength+1)/2;
                zerolength=0;
            }
        }

        if(zerolength){
            answer+=(long long)zerolength*(zerolength+1)/2;
        }

        return answer;

    }
};
