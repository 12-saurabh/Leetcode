class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {

        unordered_set<string>st;

        for(auto &i:obstacles){
            string s=to_string(i[0])+"#"+to_string(i[1]);
            st.insert(s);
        }


        int dx[]={0,1,0,-1};
        int dy[]={1,0,-1,0};

        int x=0;
        int y=0;

        int dr=0;

        int maxi=0;

        for(int c:commands){
            if(c==-1){
                dr=(dr+1)%4;
            }
            else if(c==-2){
                dr=(dr+3)%4;
            }
            else{
                for(int step=0;step<c;step++){
                    int nx=x+dx[dr];
                    int ny=y+dy[dr];

                    string key=to_string(nx)+"#"+to_string(ny);

                    if(st.count(key)){
                        break;
                    }

                    x=nx;
                    y=ny;

                    maxi=max(maxi,x*x+y*y);
                }
            }
        }

        return maxi;

        
    }
};
