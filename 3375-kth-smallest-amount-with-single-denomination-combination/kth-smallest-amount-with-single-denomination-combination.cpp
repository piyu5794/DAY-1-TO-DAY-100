class Solution {
public:
    long gcd(long a, long b) {
        while (b != 0) {
            long temp = a % b;
            a = b;
            b = temp;
        }
        return a;
    }
    long lcm(long a, long b) { return a / gcd(a, b) * b; }
    long count(long x, vector<int> coins) {
        long ans = 0;
        long n = coins.size();
        for (int mask = 1; mask < (1 << n); mask++) {
            long multiple = 1;
            int bits = 0;
            for (int i = 0; i < n; i++) {
                if ((mask & (1 << i)) != 0) {
                    bits++;
                    multiple = lcm(multiple, coins[i]);
                    if (multiple > x)
                        break;
                }
            }
            if (multiple > x)
                continue;
            long value = x / multiple;
            if (bits % 2 == 1)
                ans += value;
            else
                ans -= value;
        }
        return ans;
    }
    long long findKthSmallest(vector<int>& coins, int k) {
        long lo = 1; 
        long hi = (long)coins[0] * k;
        for (int coin : coins)
            hi = min(hi, (long)coin * k);
        while (lo < hi) {
            long mid = lo + (hi - lo) / 2;
            if (count(mid, coins) >= k)
                hi = mid;
            else
                lo = mid + 1;
        }
        return lo;
    }
};