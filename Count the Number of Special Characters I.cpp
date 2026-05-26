class Solution {
public:
    int numberOfSpecialChars(string word) {
        
        unordered_set<char>st1;
        unordered_set<char>st2;

        for(char ch:word){
            if(ch>='a' && ch<='z'){
                st1.insert(ch);
            }
            else if(ch>='A' && ch<='Z'){
                st2.insert(ch);
            }
        }

        int count=0;
        for(char ch:st1){
            if(st2.count(toupper(ch))){
                count++;
            }
        }

        return count;
    }
};
