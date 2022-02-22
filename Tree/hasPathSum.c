/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

#include <stdbool.h>
#include <stddef.h>

  struct TreeNode {
      int val;
      struct TreeNode *left;
      struct TreeNode *right;
  };
bool add_sum_node(struct TreeNode* node, int curr_sum, int targetSum)
{
    if (node==NULL) return false;

    if (node->left==NULL && node->right==NULL)
    {// no child: leaf.
        if (curr_sum+node->val==targetSum)
            return true; // sums up to the target.
        else
            return false; // not a good answer.
    }
    else
    {
        if (add_sum_node(node->left, curr_sum+node->val, targetSum)) // try left
            return true;
        else if (add_sum_node(node->right, curr_sum+node->val, targetSum)) // try right
            return true;
        else
            return false;
    }
    return false;
}
bool hasPathSum(struct TreeNode* root, int targetSum){
    if (root==NULL) return false;
    bool result = add_sum_node(root, 0, targetSum);
    return result;
}


