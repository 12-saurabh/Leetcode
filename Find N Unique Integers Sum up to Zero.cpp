class Solution {
public:
    vector<int> sumZero(int n) {
        
        vector<int>ans;

        ans.push_back(n*(1-n)/2);

        for(int i=1;i<n;i++){
            ans.push_back(i);
        }

        return ans;




    }
};
