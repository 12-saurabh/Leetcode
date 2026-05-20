class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        
        int n=A.size();

        unordered_map<int,int>mp;

        vector<int>C;
        int ans=0;
        for(int i=0;i<n;i++){
            mp[A[i]]++;
            mp[B[i]]++;

            if(mp[A[i]]>1 && A[i]!=B[i]){
                ans++;
            }
            if(mp[B[i]]>1){
                ans++;
            }

            C.push_back(ans);
        }

        return C;

        
    }
};
