class Solution {
public:

    bool solve(char a,char b){
        return abs(a-b)==1 || (a=='a' && b=='z') || (a=='z' && b=='a');
    }
    string resultingString(string s) {
        string stack;

        for(char i:s){
            if(!stack.empty() && solve(stack.back(),i)){
                stack.pop_back();
            }
            else{
                stack.push_back(i);
            }
            
        }

        return stack;
        
    }
};©leetcode
