class Solution {
public:

    string solve(int x, int B) {
        
        string ans = "";
        
        string ch = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        
        if (x == 0){

            return "0";
            
        } 
        
        while (x > 0) {
           
            ans = ch[x % B] + ans;
            
            x /= B;
        }
        
        return ans;
    }
    string concatHex36(int n) {

        
        int a = n * n;
        
        int b = n * n * n;
        
        string s16 = solve(a, 16);
        
        string s36 = solve(b, 36);
        
        return s16 + s36;
        
        
    }
};
