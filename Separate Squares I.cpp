class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        double area=0;
        double low=2e9;
        double high=0;

        for(auto &s:squares){
            double y=s[1];
            double l=s[2];

            area+=l*l;
            low=min(low,y);
            high=max(high,y+l);
        }

        double target=area/2.0;

        for(int i=0;i<100;i++){
            double mid=low+(high-low)/2.0;
            double curr=0;

            for(auto &s:squares){
                double y=s[1];
                double l=s[2];

                double below=max(0.0,min(l,mid-y));
                curr+=below*l;
            }

            if(curr<target){
                low=mid;
            }
            else{
                high=mid;
            }
        }

        return high;
        
    }
};
