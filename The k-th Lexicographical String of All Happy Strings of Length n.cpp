class Solution {
public:
    string getHappyString(int n, int k) {
        vector<string>q={"a", "b", "c"};

        for (int len=2;len<=n;len++) {
            vector<string>next;
            for (string& s:q) {
                for (char ch:{'a','b','c'}) {
                    if (s.back()!=ch) {
                        next.push_back(s+ch);
                    }
                }
            }
            q=next;
        }
        if(n==1) {
            if(k>3) return "";
            return q[k-1];
        }
        if (k>q.size()) return "";
        return q[k-1];
    }
};
