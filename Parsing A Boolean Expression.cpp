class Solution {
public:
    bool parseBoolExpr(string expression) {
        
        stack<char> st;

        for (char ch : expression) {
            if (ch == ',') continue;

            if (ch != ')') {
                st.push(ch);
            } 
            else {
                vector<bool> vals;
                while (st.top() != '(') {
                    vals.push_back(st.top() == 't');
                    st.pop();
                }
                st.pop();  
                char op = st.top();
                st.pop();

                bool result;
                if (op == '!') {
                    result = !vals[0];
                }
                else if (op == '&') {
                    result = true;
                    for (bool val : vals) result &= val;
                } 
                else if (op == '|') {
                    result = false;
                    for (bool val : vals) result |= val;
                }

                st.push(result ? 't' : 'f');
            }
        }
        
        return st.top() == 't';
    }
};
