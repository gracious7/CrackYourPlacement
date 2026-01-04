class Solution {
public:
    bool isPrime(int x) {
        if (x < 2) return false;
        for (int i = 2; i * i <= x; i++)
            if (x % i == 0) return false;
        return true;
    }

    int sumFourDivisors(vector<int>& nums) {
        int totalSum = 0;

        for (int x : nums) {

            // Case 1: p³
            int p = round(cbrt(x));
            if (p * p * p == x && isPrime(p)) {
                totalSum += (1 + p + p*p + x);
                continue; // done with this number
            }

            // Case 2: p × q
            for (int i = 2; i * i <= x; i++) {
                if (x % i == 0) {
                    int j = x / i;
                    if (i != j && isPrime(i) && isPrime(j)) {
                        totalSum += (1 + i + j + x);
                    }
                    break; // only first factor needed
                }
            }
        }

        return totalSum;
    }
};