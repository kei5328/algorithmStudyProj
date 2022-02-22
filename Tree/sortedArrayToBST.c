
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


struct TreeNode* constructBST(int * nums, int left, int right)
{

    if (right<left) return NULL; // reached the base case, no children
    int mid_idx = (right-left+1)/2+left;
    //printf("(%d,%d,%d)\n", left, right, mid_idx);

    struct TreeNode * curr_node = (struct TreeNode *)malloc(sizeof(struct TreeNode));

    curr_node->val = nums[mid_idx];

    curr_node->left = constructBST(nums, left, mid_idx-1);
    curr_node->right = constructBST(nums, mid_idx+1, right);
    return curr_node;
}


struct TreeNode* sortedArrayToBST(int* nums, int numsSize){
    struct TreeNode* root = (struct TreeNode*)constructBST(nums, 0, numsSize-1);
    return root;
}

