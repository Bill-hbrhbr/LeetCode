class Solution {
public:
    string countAndSay(int n) {
        vector<string> result{"1"};
        int count;
        char curNum;
        for (int i = 1; i < 30; i++) {
            string newS;
            count = 0;
            string old = result[i - 1];
            curNum = old[0];
            for (auto iter = old.cbegin(); iter != old.cend(); iter++) {
                if (*iter == curNum)
                    count++;
                else {
                    newS += (count + '0');
                    newS += curNum;
                    count = 1;
                    curNum = *iter;
                }
            }
            newS += (count + '0');
            newS += curNum;
            result.push_back(newS);
        }
        return result[n - 1];
    }
};