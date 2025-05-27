class Solution {
public:
    long long getCutCost(int x, int k) {
       return 1LL * k * (x - k);
    }
    long long minCuttingCost(int n, int m, int k) {
    if (n <= k && m <= k) {
        return 0;
    }

    long long res = 1e18;

    if (n > k && m <= k)
        res = getCutCost(n, k);
    if (m > k && n <= k)
        res = min(res, getCutCost(m, k));

    if (n > k && m > k) {
        res = min(res, getCutCost(n, k) + getCutCost(m, k));
    }

        return res;
   }
         
};©leetcode
