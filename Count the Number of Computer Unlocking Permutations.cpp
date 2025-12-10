class Solution {
public:
    
    const int MOD=1e9+7;
    int countPermutations(vector<int>& complexity) {

        int n=complexity.size();

        int f=complexity[0];
        for(int i=1;i<n;i++){
            if(complexity[i]<=f){
                return 0;
            }
        }

        long long  fact=1;
        for(int i=2;i<n;i++){
            fact=(fact*i)%MOD;
        }

        return fact;






        
    }
};
