/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* inorderTraversal(struct TreeNode* root, int* returnSize){

    // idea:
    // choose the left node recursively.
    // if left node is null, output the val
    // then, choose the right node.
    //
    //
    uint8_t num_node;
    num_node = countBinTreeNode(root, 0);

    p_out_arr = (int*)malloc(sizeof(int)*num_node);
    num_node=traverseBinTreeNode(root, p_out_arr, 0);

    *returnSize = size;
    return p_out_arr;
}


uint8_t int countBinTreeNode(struct TreeNode* root, uint8_t size)
{
    if (root==NULL) return size;

    size=traverseBinaryTree(root->left, size);
    size=traverseBinaryTree(root->right, size+1);
    return size;
}

uint8_t int traverseBinTreeNode(struct TreeNode* root, int* p_out_arr, uint8_t size)
{
    if (root==NULL) return size;

    size=traverseBinaryTree(root->left, size);
    // put the self number into the current size;
    *(p_out_arr+size) = root->val;
    size=traverseBinaryTree(root->right, size+1);
    return size;
}
