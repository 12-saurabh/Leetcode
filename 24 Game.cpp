class Solution {
public:

    bool solve(vector<double>&nums){
        if(nums.size()==1){
            return abs(nums[0]-24)<=0.01;
        }
        for(int i=0;i<nums.size();i++){
            for(int j=0;j<i;j++){
                double a=nums[i];
                double b=nums[j];

                vector<double>next(nums.begin(),nums.end());
                next.erase(next.begin()+i);
                next.erase(next.begin()+j);

                for(double val:{a+b,a-b,b-a,a*b,a/b,b/a}){
                    next.push_back(val);
                    if(solve(next)){
                        return true;
                    }

                    next.pop_back();
                }

            }
        }

        return false;
    }
    bool judgePoint24(vector<int>& cards) {

        vector<double>nums(cards.begin(),cards.end());

        return solve(nums);
        

    }
};
