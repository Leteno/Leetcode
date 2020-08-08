#
# @lc app=leetcode id=18 lang=python3
#
# [18] 4Sum
#

# @lc code=start
class Solution:
    def fourSum(self, nums, target: int):
        length = len(nums)
        sortedNums = sorted(nums)
        result, lastI, lastJ = [], None, None
        for i in range(length):
            if lastI == sortedNums[i]:
                continue
            lastI = sortedNums[i]
            lastJ = None
            for j in range(i+1, length):
                if lastJ == sortedNums[j]:
                    continue
                lastJ = sortedNums[j]
                sum12 = sortedNums[i] + sortedNums[j]
                lo, hi, subTarget = j + 1, length - 1, target - sum12
                while lo < hi:
                    gap = subTarget - sortedNums[lo] - sortedNums[hi]
                    if gap > 0:
                        lo += 1
                    elif gap < 0:
                        hi -= 1
                    else:
                        result.append([
                            sortedNums[i], sortedNums[j],
                            sortedNums[lo], sortedNums[hi]
                        ])
                        loVal, hiVal = sortedNums[lo], sortedNums[hi]
                        while lo < hi and loVal == sortedNums[lo]:
                            lo += 1
                        while lo < hi and hiVal == sortedNums[hi]:
                            hi -= 1
        return result

# def myAssert(a, b):
#     if a != b:
#         print("expect %s\nactually %s" % (b, a))
#     assert a == b

# if __name__ == "__main__":
#     myAssert(Solution().fourSum([-7,-5,0,7,1,1,-10,-2,7,7,-2,-6,0,-10,-5,7,-8,5], 28), [[7,7,7,7]])
#     myAssert(Solution().fourSum([0,0,0,0,0], 0), [[0,0,0,0]])
#     myAssert(Solution().fourSum([1,0,-1,0,-2,2], 0), [[-1,0,0,1],[-2,-1,1,2],[-2,0,0,2]])
# @lc code=end

