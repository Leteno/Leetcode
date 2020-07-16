#
# @lc app=leetcode id=168 lang=python3
#
# [168] Excel Sheet Column Title
#

# @lc code=start
class Solution:
    # i [0, 25]
    def i2Ascii(i):
        return chr(int(i) + ord('A'))
    def convertToTitle(self, n: int) -> str:
        numbers = []
        while n > 0:
            n -= 1
            mod = n % 26
            n = int(n / 26)
            numbers.append(mod)
        result = ''
        # print('%s' % numbers)
        for i in range(len(numbers) - 1, -1, -1):
            result += Solution.i2Ascii(numbers[i])
        return result
# @lc code=end

