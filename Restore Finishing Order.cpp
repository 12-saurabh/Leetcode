class Solution {
public:
    vector<int> recoverOrder(vector<int>& order, vector<int>& friends) {

        vector<int>ans;

        for(auto i:order){
            if(find(friends.begin(),friends.end(),i)!=friends.end()){
                ans.push_back(i);
            }
            else{
                continue;
            }
        }

        return ans;
    }
};
