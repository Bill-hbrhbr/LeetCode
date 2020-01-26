class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<bool> discovered(numCourses, false);
        vector<bool> processed(numCourses, false);
        vector<int> order;
        
        vector<vector<int>> edgeList(numCourses);
        for (auto &p: prerequisites) {
            edgeList[p[1]].push_back(p[0]);
        }
        
        for (int i = 0; i < numCourses; ++i) {
            if (!processed[i] && !dfsDAG(edgeList, discovered, processed, order, i)) {
                return {};
            }
        }
        reverse(order.begin(), order.end());
        return order;
    }
private:
    bool dfsDAG(vector<vector<int>>& edgeList, 
                vector<bool>& discovered, 
                vector<bool>& processed,
                vector<int>& order,
                int node) 
    {
        if (processed[node]) {
            return true;
        } else if (discovered[node]) {
            return false;
        } else {
            discovered[node] = true;
        }
        for (auto &nextNode: edgeList[node]) {
            if (!dfsDAG(edgeList, discovered, processed, order, nextNode)) {
                return false;
            }
        }
        processed[node] = true;
        order.push_back(node);
        return true;
    }
};