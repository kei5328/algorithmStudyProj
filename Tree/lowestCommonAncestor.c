/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    // if current node's value is between p and q, it is the lowest common and return the value

    if (root==NULL || p==NULL || q==NULL) return NULL;
    struct TreeNode * lca_node = root;

    if ((p->val<=root->val && root->val<=q->val) ||  (q->val<=root->val && root->val<=p->val))
    {// current node is the LCA. return current node.
        return root;
    }
    else if ( p->val < root->val && q->val < root->val)// both p and q are on the left side of the tree
        lca_node = lowestCommonAncestor(root->left, p, q);
    else if ( p->val > root->val && q->val > root->val) // both p and q are on the right side of the tree
        lca_node = lowestCommonAncestor(root->right, p, q);
    else
    {// should not come in here.
        lca_node = NULL;
    }
    return lca_node;
}



