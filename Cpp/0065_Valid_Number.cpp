class Solution {
public:
    inline bool isDigit(char &ch) {
        if (ch >= '0' && ch <= '9') {
            return true;
        } else {
            return false;
        }
    }
    bool isNumber(string s) {
        decltype(s.size()) index = 0;
        int dot = 0;
        bool digit = false;
        while (index < s.size() && s[index] == ' ') {
            ++index;
        }
        if (index == s.size()) {
            return false;
        } else if (s[index] == '+' || s[index] == '-' || s[index] == '.') {
            if (s[index] == '.') {
                ++dot;
            }
            ++index;
            if (index == s.size()) {
                return false;
            }
        }
        while (index < s.size() && (isDigit(s[index]) || s[index] == '.')) {
            if (s[index] == '.') {
                ++dot;
            }
            if (isDigit(s[index])) {
                digit = true;
            }
            ++index;
        }
        if (dot > 1 || !digit) {
            return false;
        }
        if (index == s.size()) {
            return true;
        } else if (s[index] != 'e' && s[index] != 'E') {
            while (index < s.size() && s[index] == ' ') {
                ++index;
            }
            return index == s.size() ? true : false;
        }
        ++index;
        if (index == s.size()) {
            return false;
        } else if (s[index] == '+' || s[index] == '-') {
            ++index;
            if (index == s.size()) {
                return false;
            }
        }
        digit = false;
        while (index < s.size() && isDigit(s[index])) {
            ++index;
            digit = true;
        }
        while (index < s.size() && s[index] == ' ') {
            ++index;
        }
        return digit && index == s.size() ? true : false;
    }
};