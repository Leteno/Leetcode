/*
 * @lc app=leetcode id=119 lang=c
 *
 * [119] Pascal's Triangle II
 */

// @lc code=start


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getRow(int rowIndex, int* returnSize){
    int realIndex = rowIndex + 1;
    int* result = malloc(realIndex * sizeof(int));
    int i, j;
    for (i = 0; i < realIndex; ++i) {
        for (j = i - 1; j >= 1; --j ) {
            result[j] = result[j] + result[j - 1];
        }
        result[0] = 1;
        result[i] = 1;
    }
    *returnSize = realIndex;
    return result;
}

// void test(int rowIndex, int expectSize, int* expectRow) {
//     int returnSize;
//     int* row = getRow(rowIndex, &returnSize);
//     if (returnSize != expectSize) {
//         printf("returnSize wrong: %d\n", returnSize);
//     }
//     int min = returnSize > expectSize ? expectSize : returnSize;
//     int i;
//     for (i = 0; i < min; ++i) {
//         if (expectRow[i] != row[i]) {
//             printf("wrong at %d, expect: %d, now: %d\n",
//                 i, expectRow[i], row[i]);
//         }
//     }
// }

// int main() {
//     int a[] = {1};
//     test(1, 1, a);
//     int b[] = {1, 1};
//     test(2, 2, b);
//     int c[] = {1, 2, 1};
//     test(3, 3, c);
//     int d[] = {1, 3, 3, 1};
//     test(4, 4, d);
//     int f[] = {1, 4, 6, 4, 1};
//     test(5, 5, f);
//     return 0;
// }
// @lc code=end

