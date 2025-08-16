class Solution {
public:
    int maximum69Number (int num) {

        for(int i=1000;i>0;i/=10){
            int x=num/i;
            int d=x%10;
            if(d==6){
                return num+3*i;
            }
        }
        return num;


        
    }
};
