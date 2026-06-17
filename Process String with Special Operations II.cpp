class Solution {
public:
    char processStr(string s, long long k) {

        long long l=0;

        for(char ch:s){
            if(islower(ch)){
                l++;
            }
            else if(ch=='*'){
                if(l>0){
                    l--;
                }
            }
            else if(ch=='#'){
                l*=2;
            }
        }

        if(k>=l){
            return '.';
        }

        for(int i=s.size()-1;i>=0;i--){
            char ch=s[i];

            if(islower(ch)){
                if(k==l-1){
                    return ch;
                }
                l--;
            }
            else if(ch=='*'){
                l++;
            }
            else if(ch=='#'){
                l/=2;
                k%=l;
            }
            else if(ch=='%'){
                k=l-1-k;
            }

        }

        return '.';

    }
};
