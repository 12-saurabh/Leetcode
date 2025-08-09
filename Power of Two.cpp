class Solution {
public:
    bool isPowerOfTwo(int n) {

        bool f=false;
        for(int i=0;i<32;i++){
            if(pow(2,i)==n){
                f=true;
                break;
            }
        }

        if(f){
            return true;
        }
        else{
            return false;
        }


        
    }
};
