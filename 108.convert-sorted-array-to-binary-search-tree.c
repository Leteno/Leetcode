/*
 * @lc app=leetcode id=108 lang=c
 *
 * [108] Convert Sorted Array to Binary Search Tree
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode* getTreeNode(int* nums, int numStart, int numEnd) {
    if (!nums || numStart > numEnd) { return NULL; }
    struct TreeNode* currentNode = malloc(sizeof(struct TreeNode));
    int mid = numStart + (numEnd - numStart + 1) / 2;
    currentNode->val = nums[mid];
    currentNode->left = getTreeNode(nums, numStart, mid - 1);
    currentNode->right = getTreeNode(nums, mid + 1, numEnd);
    return currentNode;
}

struct TreeNode* sortedArrayToBST(int* nums, int numsSize){
    return getTreeNode(nums, 0, numsSize - 1);
}


// @lc code=end

