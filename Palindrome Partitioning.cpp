class Solution {
public:
  
    bool isPallindrome(string &str,int start,int end){
        while(start<=end){
            if(str[start]!=str[end]){
                return false;
            }
            start++;
            end--;
        }

        return true;
    }
    void rec(int i,vector<vector<string>>&ans,vector<string>&curr,string s){
        if(i==s.size()){
            ans.push_back(curr);
            return;
        }

        for(int j=i;j<s.size();j++){
            if(isPallindrome(s,i,j)){
                curr.push_back(s.substr(i,j-i+1));
                rec(j+1,ans,curr,s);
                curr.pop_back();
            }
        }



    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>curr;

        rec(0,ans,curr,s);

        return ans;


        
    }
};
