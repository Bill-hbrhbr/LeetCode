class Solution {
public:
    int reverse(int x) {
        long long longX = static_cast<long long> (x);
        if (longX == 0) {
            return 0;
        }
        long long n = 0;
        int sign;
        if (longX > 0) {
            sign = 1;
        } else {
            sign = -1;
            longX = -1 * longX;
            
        }
        while (longX > 0) {
            n *= 10;
            n += longX % 10;
            longX /= 10;
        }
        n = sign * n;
        if (n > INT_MAX || n < INT_MIN) {
            return 0;
        } else {
            return static_cast<int> (n);
        }
    }
};