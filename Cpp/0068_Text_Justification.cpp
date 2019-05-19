class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> result(1);
        int curLength = 0, curWordCount = 0, start = 0, end = 0;
        int curIndex = 0;
        for (; end < words.size(); ++end) {
            if (curLength + curWordCount + words[end].size() > maxWidth) {
                fitString(result[curIndex], words, curLength, curWordCount, maxWidth, start, end);
                ++curIndex;
                result.push_back("");
                curLength = words[end].size();
                curWordCount = 1;
                start = end;
            } else {
                curLength += words[end].size();
                ++curWordCount;
            }
        }
        for (;start < end - 1; ++start) {
            result[curIndex] += words[start];
            result[curIndex] += ' ';
        }
        result[curIndex] += words[start];
        result[curIndex] += string(maxWidth - result[curIndex].size(), ' ');
        return result;
    }
private:
    void fitString(string &target, vector<string> &words, int &curLength, 
                   int &curWordCount, int &maxWidth, int &start, int &end) {
        int leftOverSpace, withExtra, normalSpaceCount;
        if (curWordCount == 1) {
            target += words[start];
            target += string(maxWidth - curLength, ' ');
        } else {
            leftOverSpace = maxWidth - curLength;
            withExtra = leftOverSpace % (curWordCount - 1);
            normalSpaceCount = leftOverSpace / (curWordCount - 1);
            while (start < end - 1) {
                target += words[start];
                if (withExtra > 0) {
                    --withExtra;
                    target += string(normalSpaceCount + 1, ' ');
                } else {
                    target += string(normalSpaceCount, ' ');
                }
                ++start;
            }
            target += words[start];
        }
    }
};