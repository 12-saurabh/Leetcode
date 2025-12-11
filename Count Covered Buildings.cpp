class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {

        vector<int>minx(n+1,n+1);
        vector<int>maxx(n+1,0);

        vector<int>miny(n+1,n+1);
        vector<int>maxy(n+1,0);

        for(auto b:buildings){

            int i=b[0];
            int j=b[1];

            minx[j]=min(minx[j],i);
            maxx[j]=max(maxx[j],i);

            miny[i]=min(miny[i],j);
            maxy[i]=max(maxy[i],j);
        }

        int ans=0;

        for(auto b:buildings){
            int i=b[0];
            int j=b[1];

            if(minx[j]<i && i<maxx[j] && miny[i]<j && j<maxy[i]){
                ans+=1;
            }
        }

        return ans;
        

    }
};
