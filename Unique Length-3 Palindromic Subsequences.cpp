class Solution {
public:
    int countPalindromicSubsequence(string s) {

        int n=s.length();

        unordered_map<char,vector<int>>mp;

        for(int i=0;i<n;i++){
            mp[s[i]].push_back(i);
        }

        int count=0;

        for(auto x:mp){
            vector<int>v=x.second;

            int start=v[0];
            int end=v[v.size()-1];

            if(end-start<=1){
                continue;
            }

            unordered_set<char>ans;

            for(int i=start+1;i<end;i++){
                ans.insert(s[i]);
            }

            count+=ans.size();
        }

        return count;
    
        
    }
};
