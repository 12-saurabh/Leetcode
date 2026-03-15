class Fancy {
public:
    vector<int>v;
    long long sum=0;
    long long mul=1;
    long long MOD=1e9+7;

    long long power(long long base,long long exp){
        long long ans=1;
        base%=MOD;

        while(exp){
            if(exp&1){
                ans=(ans*base)%MOD;
            }
            exp/=2;
            base=(base*base)%MOD;
        }

        return ans;
    }

    long long modInverse(long long n){
        return power(n,MOD-2);
    }
    Fancy() {
        
    }
    
    void append(int val) {
        long long t=val;
        long long base=((t-sum+MOD)%MOD*modInverse(mul))%MOD;
        v.push_back(base);
        
    }
    
    void addAll(int inc) {
        sum=(sum+inc)%MOD;
        
    }
    
    void multAll(int m) {
        mul=(mul*m)%MOD;
        sum=(sum*m)%MOD;
    }
    
    int getIndex(int idx) {
        if(idx>=v.size()){
            return -1;
        }

        return (v[idx]*mul+sum)%MOD;
    }
};

/**
 * Your Fancy object will be instantiated and called as such:
 * Fancy* obj = new Fancy();
 * obj->append(val);
 * obj->addAll(inc);
 * obj->multAll(m);
 * int param_4 = obj->getIndex(idx);
 */
