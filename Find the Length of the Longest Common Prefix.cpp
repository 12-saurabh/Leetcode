class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {

        unordered_set<int>st;

        unordered_set<int>st1(arr1.begin(),arr1.end());
        unordered_set<int>st2(arr2.begin(),arr2.end());

        int ans=0;
        
        for(auto i:st2){
            string curr;

            string x=to_string(i);

            for(char ch:x){
                curr+=ch;
                int v=stoi(curr);

                if(!st.count(v)){
                    st.insert(v);
                }
            }
        }

        for(auto i:st1){
            string curr;
            string x=to_string(i);

            for(char ch:x){
                curr+=ch;
                int v=stoi(curr);

                if(st.count(v)){
                    ans=max(ans,(int)curr.size());
                }
            }
        }

        return ans;
    }
};
