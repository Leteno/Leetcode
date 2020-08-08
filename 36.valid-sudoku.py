#
# @lc app=leetcode id=36 lang=python3
#
# [36] Valid Sudoku
#

# @lc code=start
class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        size = 9
        nums = {}
        def emptyArray():
            nums['1'] = False
            nums['2'] = False
            nums['3'] = False
            nums['4'] = False
            nums['5'] = False
            nums['6'] = False
            nums['7'] = False
            nums['8'] = False
            nums['9'] = False

        # rows
        for i in range(size):
            emptyArray()
            for m in range(size):
                if board[i][m] == '.':
                    continue
                if nums[board[i][m]]:
                    return False
                nums[board[i][m]] = True
        # cols
        for i in range(size):
            emptyArray()
            for m in range(size):
                if board[m][i] == '.':
                    continue
                if nums[board[m][i]]:
                    return False
                nums[board[m][i]] = True
        # cells
        for i in range(size):
            rowBegin = i // 3 * 3
            colBegin = i % 3 * 3
            emptyArray()
            for m in range(3):
                for n in range(3):
                    a, b = rowBegin + m, colBegin + n
                    if board[a][b] == '.':
                        continue
                    if nums[board[a][b]]:
                        return False
                    nums[board[a][b]] = True
        return True
# @lc code=end

