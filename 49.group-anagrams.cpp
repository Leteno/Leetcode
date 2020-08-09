/*
 * @lc app=leetcode id=49 lang=cpp
 *
 * [49] Group Anagrams
 */

// @lc code=start
#include <algorithm>
#include <map>
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    string genCode(string str) {
        sort(str.begin(), str.end());
        return str;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> code2Strings;
        for (auto& str : strs) {
            const auto& code = genCode(str);
            code2Strings[code].push_back(str);
        }
        vector<vector<string>> result;
        for (auto& pair : code2Strings) {
            result.push_back(pair.second);
        }
        return result;
    }
};
// @lc code=end

