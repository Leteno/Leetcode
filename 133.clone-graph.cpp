/*
 * @lc app=leetcode id=133 lang=cpp
 *
 * [133] Clone Graph
 */

// @lc code=start
// Definition for a Node.
#include <map>
/*
#include <vector>
using namespace std;
class Node {
public:
    int val;
    vector<Node*> neighbors;
    
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* root) {
        if (root == nullptr) return nullptr;
        map<int, Node*> newNodeMap;
        vector<Node*> scanList;
        scanList.push_back(root);
        Node* cur;
        while (!scanList.empty()) {
            cur = scanList.back();
            scanList.pop_back();
            if (newNodeMap.find(cur->val) != newNodeMap.end()) {
                // visited before
                continue;
            }
            newNodeMap.insert(std::pair(cur->val, new Node(cur->val)));
            for (auto node : cur->neighbors) {
                scanList.push_back(node);
            }
        }

        scanList.push_back(root);
        bool visited[101];
        memset(visited, false, 101 * sizeof(bool));
        while (!scanList.empty()) {
            cur = scanList.back();
            scanList.pop_back();
            if (visited[cur->val]) {
                continue;
            }
            visited[cur->val] = true;

            auto target = newNodeMap.find(cur->val);
            for (auto node : cur->neighbors) {

                auto newNode = newNodeMap.find(node->val);
                target->second->neighbors.push_back(newNode->second);

                if (!visited[node->val]) {
                    scanList.push_back(node);
                }
            }
        }
        return newNodeMap.find(root->val)->second;
    }
};
// @lc code=end

