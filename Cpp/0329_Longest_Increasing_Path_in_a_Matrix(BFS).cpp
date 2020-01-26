class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (matrix.empty()) {
            return 0;
        }
        int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        int row = matrix.size();
        int col = matrix[0].size();
        
        vector<vector<int>> in_degree(row, vector<int>(col, 0));
        deque<vector<int>> q;
        int i, j, k, newi, newj;
        for (i = 0; i < row; ++i) {
            for (j = 0; j < col; ++j) {
                for (k = 0; k < 4; ++k) {
                    newi = i + directions[k][0];
                    newj = j + directions[k][1];
                    if (newi >= 0 && newi < row && newj >= 0 && newj < col &&
                        matrix[i][j] < matrix[newi][newj]) {
                        ++in_degree[i][j];
                    }
                }
                if (in_degree[i][j] == 0) {
                    q.push_back({i, j});
                }
            }
        }
        
        int count = 0, currSize;
        while (!q.empty()) {
            currSize = q.size();
            while (currSize-- > 0) {
                i = q.front()[0];
                j = q.front()[1];
                q.pop_front();
                for (k = 0; k < 4; ++k) {
                    newi = i + directions[k][0];
                    newj = j + directions[k][1];
                    if (newi >= 0 && newi < row && newj >= 0 && newj < col &&
                        matrix[i][j] > matrix[newi][newj]) {
                        --in_degree[newi][newj];
                        if (in_degree[newi][newj] == 0) {
                            q.push_back({newi, newj});
                        }
                    }
                }
            }
            ++count;
        }   
        return count;
    }
};