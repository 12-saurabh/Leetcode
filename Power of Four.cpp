class Solution {
public:
    bool isPowerOfFour(int n) {

        bool flag=false;
        for(int i=0;i<16;i++){

            if(pow(4,i)==n){
                flag=true;
                break;
            }
        }
        if(flag){
            return true;
        }
        else{
            return false;
        }
    }
};
