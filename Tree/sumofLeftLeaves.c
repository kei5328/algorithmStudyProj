/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int addLeftLeaves(struct TreeNode* node, bool left_call)
{
    int right_val = 0;
    int left_val = 0;
    if (node->left==NULL && node->right==NULL)
    {
        if (left_call) // this is a left leaf.
            return node->val;
        else // this is not a left leaf, but rather it's a right leaf.
            return 0;
    }
    // got here means this node is not a leaf.
    if (node->left)
    {// left is not null;
        left_val = addLeftLeaves(node->left, 1);
    }

    if (node->right)
    {
        right_val = addLeftLeaves(node->right, 0);
    }

    return left_val+right_val;
}

int sumOfLeftLeaves(struct TreeNode* root){
    int result = addLeftLeaves(root, 0);
    return result;
}

