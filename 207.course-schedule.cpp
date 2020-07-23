/*
 * @lc app=leetcode id=207 lang=cpp
 *
 * [207] Course Schedule
 */

// @lc code=start

#include <set>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        if (numCourses <= 1) return true;

        vector<int> indegree(numCourses, 0);
        vector<vector<int>> adj(numCourses);
        for (auto& v : prerequisites) {
            indegree[v[1]]++;
            adj[v[0]].push_back(v[1]);
        }

        vector<int> scan;

        for (int i = 0; i < numCourses; ++i) {
            if (indegree[i] == 0) {
                scan.push_back(i);
            }
        }

        while (scan.size()) {
            int cur = scan.back();
            scan.pop_back();
            for (int i : adj[cur]) {
                indegree[i]--;
                if (indegree[i] == 0) {
                    scan.push_back(i);
                }
            }
            // cur is clean, remove it.
            numCourses --;
        }
        // Any course left means loop.
        return numCourses == 0;
    }
};
// @lc code=end

