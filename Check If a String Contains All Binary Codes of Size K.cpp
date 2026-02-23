class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int n=s.length();

        if(k>n){
            return false;
        }

        int x=1<<k;
        if(n-k+1<x){
            return false;
        }

        unordered_set<string>st;

        for(int i=0;i<=n-k;i++){
            st.insert(s.substr(i,k));

            if((int)st.size()==x){
                return true;
            }
        }

        if(st.size()==x){
            return true;
        }
        else{
            return false;
        }
    }
};
