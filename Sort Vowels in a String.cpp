class Solution {
public:
    string sortVowels(string s) {
        string str="";
        for(int i=0;i<s.length();i++){
            char ch=tolower(s[i]);
            if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u'){
                str+=s[i];
            }
        }
        sort(str.begin(),str.end());
        int j=0;
        for(int i=0;i<s.length();i++){
            char ch=tolower(s[i]);
            if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u'){
                s[i]=str[j];
                j++;
            }
        }
        return s;
    }
};
