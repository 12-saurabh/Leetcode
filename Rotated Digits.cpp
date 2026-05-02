class Solution {
public:
    int rotatedDigits(int n) {
        
        int count=0;
        for(int i=1;i<=n;i++){
            int curr=i;

            bool check=false;
            bool valid=true;

            while(curr>0 && valid){
                int d=curr%10;

                if(d==3 || d==4 || d==7){
                    valid=false;
                }
                else if(d==2 || d==5 || d==6 || d==9){
                    check=true;
                }

                curr/=10;
            }

            if(valid && check){
                count++;
            }

        }

        return count;
    }
};
