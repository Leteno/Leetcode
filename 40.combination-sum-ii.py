#
# @lc app=leetcode id=40 lang=python3
#
# [40] Combination Sum II
#

# @lc code=start
class Solution:
    def combinationSum2(self, candidates, target: int):
        result = []
        candidates = sorted(candidates)
        def combinationSub(candidates, target, stack, begin, size):
            if target == 0:
                result.append(stack[:])
                return
            lastVal = None
            for i in range(begin, size):
                if lastVal == candidates[i]:
                    continue
                lastVal = candidates[i]
                if target >= candidates[i]:
                    stack.append(candidates[i])
                    combinationSub(candidates, target - candidates[i], stack, i+1, size)
                    stack.pop()
        combinationSub(candidates, target, [], 0, len(candidates))
        return result

def myAssert(a, b):
    if a != b:
        print("expect: %s\ngot: %s" % (b, a))
        assert a == b

if __name__ == "__main__":
    myAssert(Solution().combinationSum2([10, 1, 2, 7, 6, 1, 5], 8), [[1, 1, 6], [1, 2, 5], [1, 7], [2, 6]])
    myAssert(Solution().combinationSum2([2, 5, 2, 1, 2], 5), [[1,2,2], [5]])
# @lc code=end

