class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        
        long long oddsum=0;
        long long evensum=0;

        for(int i=1;i<=2*n;i++){
            if(i%2){
                oddsum+=i;
            }
            else{
                evensum+=i;
            }
        }


        return __gcd(oddsum,evensum);
    }
};
