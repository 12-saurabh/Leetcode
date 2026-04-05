class Solution {
public:
    bool judgeCircle(string moves) {
        int hr=0;
        int vt=0;

        for(char ch:moves){
            if(ch=='U'){
                vt++;
            }
            else if(ch=='D'){
                vt--;
            }
            else if(ch=='R'){
                hr++;
            }
            else if(ch=='L'){
                hr--;
            }
        }

        if(hr==0 && vt==0){
            return true;
        }
        else{
            return false;
        }
    }
};
