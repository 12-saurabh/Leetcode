class Solution {
public:
    bool isPrime(long long n) {
        if (n <= 1) return false;
        if (n == 2) return true;
        if (n % 2 == 0) return false;
        for (long long i = 3; i * i <= n; i += 2) {
            if (n % i == 0) return false;
        }
        return true;
    }
    
    long long sumOfLargestPrimes(string s) {
        set<long long> st;
        int n = s.size();

        for (int i = 0; i < n; ++i) {
            string temp = "";
            for (int j = i; j < n; ++j) {
                temp += s[j];
                long long num = stoll(temp); 
                st.insert(num);
            }
        }

        vector<long long> p;
        for (long long num : st) {
            if (isPrime(num)) {
                p.push_back(num);
            }
        }

        sort(p.rbegin(), p.rend());

        long long sum = 0;
        for (int i = 0; i < min(3, (int)p.size()); ++i) {
            sum += p[i];
        }

        return sum;
    }
};
