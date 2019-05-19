/*
 * Equally weighted hash algorithm
 * O(n) beats 99.21% C++ solutions
 */
<<<<<<< HEAD
#include <algorithm>
=======
#include <algorithm> //Reverse string objects
>>>>>>> 997459b0b331241d258a2249f8c4f1a006b26168
using namespace std;
class Solution {
public:
    bool check(const string &s, int endIndex) {
        int left = 0, right = endIndex;
        while (left < right) {
            if (s[left] != s[right]) {
                return false;
            }
            ++left;
            --right;
        }
        return true;
    }
    string shortestPalindrome(string s) {
        const int PRIME = 999983; //Large Prime
        int length = s.size();
        string returnStr(s);
        reverse(returnStr.begin(), returnStr.end());
        if (length < 2) {
            return returnStr;
        }
        int hash1 = 0, hash2 = 0;
        for (int i = 0; i < (length + 1) / 2; ++i) {
            hash1 = (hash1 + s[i]) % PRIME;
        }
        for (int i = length / 2; i < length; ++i) {
            hash2 = (hash2 + s[i]) % PRIME;
        }
        int fastIndex = length - 1;
        int centerIndex = length / 2;
        while (fastIndex >= 0) {
            if (hash1 == hash2 && check(s, fastIndex)) {
                break;
            }
            hash2 = (hash2 + PRIME - s[fastIndex]) % PRIME;
            if (fastIndex % 2 == 1) {
                --centerIndex;
                hash2 = (hash2 + s[centerIndex]) % PRIME;
            } else {
                hash1 = (hash1 + PRIME - s[centerIndex]) % PRIME;
            }
            --fastIndex;
        }
        
        for (int i = fastIndex + 1; i < length; ++i) {
            returnStr += s[i]; //Efficient concatenation
        }
        return returnStr;
    }
};
