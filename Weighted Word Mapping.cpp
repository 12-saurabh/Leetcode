class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {

        string ans="";

        for(string &i:words){
            int sum=0;
            for(char c:i){
                sum+=weights[c-'a'];
            }

            int m=sum%26;
            char ch='z'-m;

            ans.push_back(ch);
        }

        return ans;
    }
};
