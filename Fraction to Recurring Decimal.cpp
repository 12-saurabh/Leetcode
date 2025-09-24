class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {

        if(!numerator){
            return "0";
        }

        string res;

        if((denominator<0)^(numerator<0)){
            res+="-";
        }

        long long n=llabs((long long)numerator);
        long long d=llabs((long long)denominator);

        res+=to_string(n/d);

        long long rem=n%d;
        if(!rem){
            return res;
        }

        res+=".";

        unordered_map<long long,int>mp;

        while(rem){
            if(mp.count(rem)){
                res.insert(mp[rem],"(");
                res+=")";
                break;
            }
            mp[rem]=res.size();
            rem*=10;
            res+=to_string(rem/d);
            rem%=d;

        }

        return res;
        


        
    }
};
