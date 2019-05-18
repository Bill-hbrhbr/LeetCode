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
        const int PRIME = 999983;
        int length = s.size();
        string returnStr(s);
        if (length < 2) {
            return returnStr;
        }
        int centerIndex = 0, fastIndex = 0, hash1 = 0, hash2 = 0;
        while (fastIndex < length) {
            hash2 = (hash2 + s[fastIndex]) % PRIME;
            if (fastIndex % 2 == 1) {
                hash2 = (hash2 + PRIME - s[centerIndex]) % PRIME;
                ++centerIndex;
            } else {
                hash1 = (hash1 + s[centerIndex]) % PRIME;
            }
            ++fastIndex;
        }
        fastIndex = length - 1;
        centerIndex = length / 2;
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
            returnStr = s[i] + returnStr;
        }
        return returnStr;
    }
};