class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {

        int n=points.size();
        double maxi=0;

        for(int i=0;i<n-2;i++){
            for(int j=0;j<n-1;j++){
                for(int k=0;k<n;k++){
                    int xi=points[i][0];
                    int yi=points[i][1];

                    int xj=points[j][0];
                    int yj=points[j][1];

                    int xk=points[k][0];
                    int yk=points[k][1];


                    double a=sqrt(pow(xj-xi,2)+pow(yj-yi,2));
                    double b=sqrt(pow(xj-xk,2)+pow(yj-yk,2));
                    double c=sqrt(pow(xk-xi,2)+pow(yk-yi,2));


                    double s=(a+b+c)/2;

                    double area=sqrt(s*(s-a)*(s-b)*(s-c));

                    maxi=max(maxi,area);
                }
            }
        }

        return maxi;

        
    }
};
