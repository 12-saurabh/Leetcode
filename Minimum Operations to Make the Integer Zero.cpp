class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {

        for(int i=1;i<=32;i++){
            
            long long x=num1-1ll*i*num2;

            if(x<i){
                return -1;
            }

            int y=__builtin_popcountll(x);

            if(i>=y){
                return i;
            }
        }

        return -1;
        
    }
};
