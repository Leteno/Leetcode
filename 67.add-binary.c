/*
 * @lc app=leetcode id=67 lang=c
 *
 * [67] Add Binary
 */

// @lc code=start

#include <string.h>

#define IS_ONE(ch) (ch == '1' ? 1 : 0)
#define TO_CHAR(i) (i == 0 ? '0' : '1')

char * addBinary(char * a, char * b){
    if (!*a) return b;
    if (!*b) return a;

    int l1 = strlen(a), l2 = strlen(b);
    int min = l1 > l2 ? l2 : l1;
    int max = l1 > l2 ? l1 : l2;
    int resultLen = max + 1;
    char* result = malloc((resultLen+1) * sizeof(char));
    result[resultLen] = '\0';

    int increase = 0;
    for (int i = 0; i < min; i++) {
        // add l1 and l2 [0, min)
        int i1 = l1 - i - 1; int i2 = l2 - i - 1;
        result[resultLen - i - 1] = TO_CHAR(IS_ONE(a[i1]) ^ IS_ONE(b[i2]) ^ increase);
        increase = IS_ONE(a[i1]) + IS_ONE(b[i2]) + increase > 1 ? 1 : 0;
    }

    for (int i = min; i < l1; i++) {
        // for l1 [min, l1)
        int i1 = l1 - i - 1;
        result[resultLen - i - 1] = TO_CHAR(IS_ONE(a[i1]) ^ increase);
        increase = IS_ONE(a[i1]) + increase > 1 ? 1 : 0;
    }

    for (int i = min; i < l2; i++) {
        // for l2 [min, l2)
        int i2 = l2 - i - 1;
        result[resultLen - i - 1] = TO_CHAR(IS_ONE(b[i2]) ^ increase);
        increase = IS_ONE(b[i2]) + increase > 1 ? 1 : 0;
    }

    if (increase) {
        result[0] = '1';
    } else {
        // result[0] = 0, we move one step
        for (int i = 0; i < resultLen; i++) {
            result[i] = result[i+1];
        }
    }
    return result;
}


// @lc code=end

