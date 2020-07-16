/*
 * @lc app=leetcode id=160 lang=c
 *
 * [160] Intersection of Two Linked Lists
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

int length(struct ListNode* head) {
    int len = 0;
    struct ListNode* cur = head;
    while (cur) {
        ++len;
        cur = cur->next;
    }
    return len;
}

struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    int lenA = length(headA);
    int lenB = length(headB);

    struct ListNode* pA = headA, *pB = headB;
    int i;
    for (i = lenA - lenB; i > 0; --i) {
        pA = pA->next;
    }
    for (i = lenB - lenA; i > 0; --i) {
        pB = pB->next;
    }
    while(pA != pB) {
        pA = pA->next;
        pB = pB->next;
    }
    return pA;
}
// @lc code=end

