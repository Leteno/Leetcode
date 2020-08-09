#
# @lc app=leetcode id=48 lang=python3
#
# [48] Rotate Image
#

# @lc code=start
class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        def rotateInternal(i, j, iMax):
            matrix[i][j], matrix[iMax-j][i], matrix[iMax-i][iMax-j], matrix[j][iMax-i] = \
                    matrix[iMax-j][i], matrix[iMax-i][iMax-j], matrix[j][iMax-i], matrix[i][j]

        n = len(matrix)
        iMax = n - 1
        halfN = n // 2
        midN = (n+1) // 2
        for i in range(midN):
            for j in range(halfN):
                rotateInternal(i, j, iMax)


# @lc code=end

