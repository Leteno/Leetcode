/*
 * @lc app=leetcode id=43 lang=cpp
 *
 * [43] Multiply Strings
 */

// @lc code=start
#include <string>
using namespace std;
class Solution {
public:
    string multiply(string num1, string num2) {
        int carry = 0, index, tmp;
        string buffer(num2.length() + num1.length(), '0');
        for (int m = num2.length() - 1; m >= 0; --m) {
            for (int n = num1.length() - 1; n >= 0; --n) {
                index = m + n + 1;
                tmp = (buffer[index] - '0') + (num2[m]-'0') * (num1[n]-'0') + carry;
                carry = tmp / 10;
                buffer[index] = tmp % 10 + '0';
            }
            if (carry > 0) {
                buffer[--index] += carry;
                carry = 0;
            }
        }

        int firstNotZeroIndex = buffer.find_first_not_of('0');
        if (firstNotZeroIndex != string::npos) {
            return buffer.substr(firstNotZeroIndex);
        }
        return "0";
    }
};
// @lc code=end

