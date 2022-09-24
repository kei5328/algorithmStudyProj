/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void swapTreeNodes(struct TreeNode* node)
{
    if (node==NULL) return;
    swapTreeNodes(node->left);
    swapTreeNodes(node->right);

    struct TreeNode* p_temp = node->left;
    node->left = node->right;
    node->right = p_temp;
    return;
}

struct TreeNode* invertTree(struct TreeNode* root){
    swapTreeNodes(root);
    return root;
}


