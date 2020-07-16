/*
 * @lc app=leetcode id=171 lang=c
 *
 * [171] Excel Sheet Column Number
 */

// @lc code=start


int char2int(char ch) {
    return ch - 'A' + 1;
}

int titleToNumber(char * s){
    int result = 0;
    while (*s) {
        result = result * 26 + char2int(*s);
        ++s;
    }
    return result;
}

int mainTest() {
    printf("expect: %d, result: %d\n", 1, titleToNumber("A"));
    printf("expect: %d, result: %d\n", 26, titleToNumber("Z"));
    printf("expect: %d, result: %d\n", 27, titleToNumber("AA"));
    printf("expect: %d, result: %d\n", 28, titleToNumber("AB"));
    printf("expect: %d, result: %d\n", 701, titleToNumber("ZY"));
    return 0;
}
// @lc code=end

