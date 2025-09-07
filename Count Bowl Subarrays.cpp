class Solution {
public:
    long long bowlSubarrays(vector<int>& nums) {
        int n=nums.size();

        long long answer=0;
        
        stack<int>st;

        for(int i=0;i<n;i++){
            
            while(!st.empty() && nums[st.top()]<nums[i]){
            
                st.pop();
            
                if(!st.empty()){
            
                    answer++;
                }
            }

            st.push(i);
        }

        return answer;
    }
};
