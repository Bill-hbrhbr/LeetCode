#include <cctype>
class Solution {
public:
    inline bool isAlpha(char &c) {
        c = toupper(c);
        return (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9');
    }
    
    bool isPalindrome(string s) {
        if (s.size() == 0) {
            return true;
        }
        int left = 0, right = s.size() - 1;
        while (left < right) {
            while (left < right && !isAlpha(s[left])) {
                ++left;
            }
            while (right > left && !isAlpha(s[right])) {
                --right;
            }
            if (s[left] != s[right]) {
                return false;
            } else {
                ++left;
                --right;
            }
        }
        return true;
    }
};