class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {

        int col=encodedText.size()/rows;

        vector<vector<char>>v(rows,vector<char>(col));

        int ind=0;
        for(int i=0;i<rows;i++){
            for(int j=0;j<col;j++){
                v[i][j]=encodedText[ind++];
            }
        }

        string ans="";

        for(int j=0;j<col;j++){
            int i=0;
            int k=j;

            while(i<rows && k<col){
                
                ans+=v[i][k];

                i++;
                k++;
            }

        }

        while(!ans.empty() && ans.back()==' '){
            ans.pop_back();
        }

        return ans;

        
        
    }
};
