class Solution {
public:
    string removeOuterParentheses(string s) {
        
        stack<char>st;

        string ans;
        for(auto i:s){
            if(i=='('){
                if(!st.empty()){
                    ans.push_back('(');
                }
                st.push(i);
            }
            else{
                st.pop();

                if(!st.empty()){
                    ans.push_back(')');
                }

            }
        }

        return ans;

    }
};
