/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


bool isSameTree(struct TreeNode* node1, struct TreeNode* node2){
    bool result;
    if (node1==NULL && node2==NULL) result=true; // both of them are NULL
    else if ((node1==NULL && node2!=NULL)|| (node1!=NULL && node2==NULL)) // one of them is NULL but not both.
        result=false;
    else// both of them are not null
    {
        if (node1->val!=node2->val)
        {// one of the values are different
            result = false;
        }
        else
        {// values are the same
            result = isSameTree(node1->left, node2->left); // check the left node.
            if (result) // check right node only when the left is true.
            {
                result = isSameTree(node1->right, node2->right);
            }
        }
    }
    return result;
}
