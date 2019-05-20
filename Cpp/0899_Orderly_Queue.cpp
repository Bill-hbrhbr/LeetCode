class Solution {
public:
    string orderlyQueue(string s, int k) {
        int len = s.size();
        if (k == 1) {
            string doubleStr = s + s;
            string minStr = s;
            for (int i = 1; i < len; ++i) {
                string newStr = doubleStr.substr(i, len);
                if (newStr.compare(minStr) < 0) {
                    minStr = newStr;
                }
            }
            return minStr;
        }
        vector<int> count(256, 0);
        for (int i = 0; i < len; ++i) {
            ++count[s[i]];
        }
        string result;
        for (int i = 0; i < count.size(); ++i) {
            for (int j = 0; j < count[i]; ++j) {
                result += i;
            }
        }
        return result;
    }
};