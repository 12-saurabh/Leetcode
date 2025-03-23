class Solution {
public:
    int maxContainers(int n, int w, int maxWeight) {
        int x=n*n;
        int y=w*x;

        if(y<maxWeight){
            return x;
        }
        else{
            return maxWeight/w;
        }  
    }
};
