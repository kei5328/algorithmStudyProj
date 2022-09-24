/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


bool isBalanced(struct TreeNode* root){

    int depth=checkBalanced(struct TreeNode* node);

    return (depth!=-1);

}

int checkBalanced(struct TreeNode* node)
{
    int leftDepth = 0;
    int rightDepth = 0;
    if (node->left==NULL && node->right==NULL)
    {
        return 0;
    }

    if (node->left!=NULL)
    {
        leftDepth = checkBalanced(node->left);
    }
    else
    {

    }

    if (node->right!=NULL)
    {
        rightDepth = checkBalanced(node->right);
    }
    else
    {

    }

    if (abs(rightDepth-leftDepth)>1 || leftDepth==-1 || rightDepth==-1)
        return -1;
    else if (rightDepth>leftDepth)
        return rightDepth+1;
    else
        return leftDepth+1;

}
