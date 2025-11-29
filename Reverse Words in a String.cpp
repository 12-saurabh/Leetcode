class Solution {
public:
    string reverseWords(string s) {
        
        vector<string>word;
        stringstream ss(s);
        
        string w;

        while(ss>>w){
            word.push_back(w);
        }

        reverse(word.begin(),word.end());

        string ans="";

        for(int i=0;i<word.size();i++){
            if(i){
                ans+=" ";
            }

            ans+=word[i];
        }

        return ans;

        
    }
};
