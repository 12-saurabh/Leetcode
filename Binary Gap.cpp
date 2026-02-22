class Solution {
public:
    int binaryGap(int n) {
        int l=0;
        bool found=false;
        int cur=0;
        while(n){
            if(n&1){
                l=max(l,cur);
                found=true;
                cur=1;
            }
            else{
                if(found){
                    ++cur;
                }
            }
            n>>=1;
        }
        return l;
    }
};
