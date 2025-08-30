class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
        int n=board.size();
        int m=board[0].size();

        unordered_map<char,vector<pair<int,int>>>mp;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                char ch=board[i][j];

                if(ch=='.'){
                    continue;
                }

                if(mp.find(ch)!=mp.end()){
                    for(auto x:mp[ch]){
                        int row=x.first;
                        int col=x.second;

                        if(row==i){
                            return false;
                        }
                        if(col==j){
                            return false;
                        }

                        int boxi=(row/3)*3;
                        int boxj=(col/3)*3;

                        if(i>=boxi && i<boxi+3 && j>=boxj && j<boxj+3){
                            return false;
                        }
                    }
                }

                mp[ch].push_back({i,j});

            }
        }

        return true;




    }
};
