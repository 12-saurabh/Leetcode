class Solution {
public:
    bool checkDivisibility(int n) {
        
        int sum=0;
        int product=1;
        
        int num=n;
        while(num>0){
            int d=num%10;
            sum+=d;
            product*=d;

            num/=10;
        }

        int x=sum+product;

        if(n%x==0){
            return true;
        }
        else{
            return false;
        }

    }
};
