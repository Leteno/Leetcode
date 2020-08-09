/*
 * @lc app=leetcode id=49 lang=cpp
 *
 * [49] Group Anagrams
 */

// @lc code=start
#include <map>
#include <vector>
#include <string>
#include <sstream>
using namespace std;
class Solution {
public:
    string genCode(string& str) {
        int count[26];
        memset(count, 0, 26*sizeof(int));
        for (auto ch : str) {
            count[ch - 'a']++;
        }
        stringstream ss;
        for (int i = 0; i < 26; i++) {
            if (count[i] > 0) {
                ss<<('a'+i) << count[i];
            }
        }
        return ss.str();
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> code2Strings;
        for (auto& str : strs) {
            const auto& code = genCode(str);
            auto found = code2Strings.find(code);
            if (found == code2Strings.end()) {
                code2Strings.insert(pair(code, vector<string>()));
                found = code2Strings.find(code);
            }
            found->second.push_back(str);
        }
        vector<vector<string>> result;
        for (auto& pair : code2Strings) {
            result.push_back(pair.second);
        }
        return result;
    }
};
// @lc code=end

