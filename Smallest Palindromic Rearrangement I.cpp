class Solution {
public:
    string smallestPalindrome(string s) {

        vector<int>freq(26,0);
        for(char ch:s){
            freq[ch-'a']++;
        }

        int i=0;
        int j=s.length()-1;
        string ans(s.length(),' ');
        
        for(int x=0;x<26;x++){
            while(freq[x]>=2){
                ans[i++]=char('a'+x);
                ans[j--]=char('a'+x);
                freq[x]-=2;
            }

            if(freq[x]==1){
                ans[s.length()/2]=char('a'+x);
            }
        }

        return ans;

    }
};
