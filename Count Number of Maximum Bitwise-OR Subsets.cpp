class Solution {
public:

    int f(vector<int>&nums,int index,int current,int target){
        if(index==nums.size()){
            if(current==target){
                return 1;
            }
            else{
                return 0;
            }
        }

        int notinclude=f(nums,index+1,current,target);

        int include=f(nums,index+1,current|nums[index],target);

        return notinclude+include;
    }
    int countMaxOrSubsets(vector<int>& nums) {

        int n=nums.size();

        int ans=0;
        for(int i=0;i<n;i++){
            ans=ans|nums[i]; 
        }

        return f(nums,0,0,ans);

        
    }
};
