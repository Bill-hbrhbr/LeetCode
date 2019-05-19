class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> sCount(256, 0);
        vector<int> tCount(256, 0);
        count(tCount, t);
        int first = 0;
        while (first < s.size() && tCount[s[first]] == 0) {
            ++first;
        }
        int second = first;
        char ch;
        while (second < s.size()) {
            ch = s[second];
            ++sCount[ch];
            if (tCount[ch] != 0 && sCount[ch] >= tCount[ch] && contain(sCount, tCount)) {
                break;
            }
            ++second;
        }
        if (second == s.size()) {
            return "";
        }
        int min = second - first, minFirst = first, minSecond = second;
        while (second < s.size()) {
            ch = s[first];
            --sCount[ch];
            if (sCount[ch] < tCount[ch]) {
                if (second == s.size() - 1) {
                    return s.substr(minFirst, min + 1);
                }
                while (s[++second] != ch) {
                    ++sCount[s[second]];
                    if (second == s.size() - 1) {
                        return s.substr(minFirst, min + 1);
                    }
                }
                ++sCount[ch];
            }
            while (tCount[s[++first]] == 0)
                ;
            if (min > second - first) {
                min = second - first;
                minSecond = second;
                minFirst = first;
            }
        }
        return s.substr(minFirst, min + 1);
    }

private:
    bool contain(vector<int> &sCount, vector<int> &tCount) {
        for (int i = 0; i < sCount.size(); ++i) {
            if (sCount[i] < tCount[i]) {
                return false;
            }
        }
        return true;
    }
    inline void count(vector<int> &vec, string &s) {
        for (const auto &ch: s) {
            ++vec[ch];
        }
    }
};