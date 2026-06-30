class Solution {
public:
    int numberOfSubstrings(string s) {
        
        unordered_map<char,int>mp;

        mp['a']=0;
        mp['b']=0;
        mp['c']=0;

        int count=0;
        int l=0;

        for(int r=0;r<s.length();r++){
            mp[s[r]]++;
            while(mp['a']>0 && mp['b']>0 && mp['c']>0){
                count+=s.length()-r;
                mp[s[l]]--;
                l++;
            }
        }

        return count;

    }
};
