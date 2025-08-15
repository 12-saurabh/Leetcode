class Solution {
public:
    string convert(string s, int numRows) {
        
        if(numRows==1 || numRows>=s.length()){
            return s;
        }

        int index=0;
        int curr=1;

        vector<vector<char>>v(numRows);

        for(char i:s){
            v[index].push_back(i);
            if(index==0){
                curr=1;
            }
            else if(index==numRows-1){
                curr=-1;
            }
            index+=curr;
        }

        string ans;
        for(auto x:v){
            for(char i:x){
                ans+=i;

            }
        }

        return ans;



    }
};
