/*
 * @lc app=leetcode id=28 lang=c
 *
 * [28] Implement strStr()
 */

// @lc code=start


int strStr(char * haystack, char * needle){
    if (!*needle) return 0;
    char* p = haystack;
    int index = 0;
    while (*p) {
        if (*p == *needle) {
            char* ph = p; char* pn = needle;
            while (*ph && *ph == *pn) {
                ++ph; ++pn;
            }
            if (!*pn) return index;
        }
        ++p;
        ++index;
    }
    return -1;
}


// @lc code=end

