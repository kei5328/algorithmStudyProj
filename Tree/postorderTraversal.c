/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool traverseTree(struct TreeNode* p_node, bool fill, int* num_nodes, int * out_arr)
{

    if (p_node==NULL) return 1;
    // left
    bool left_visited = traverseTree(p_node->left, fill, num_nodes, out_arr);

    // right
    bool right_visited = traverseTree(p_node->right, fill, num_nodes, out_arr);


    if (fill && out_arr!=NULL) (*(out_arr+(*num_nodes))) = p_node->val;
        (*num_nodes)++;
    return 1;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* postorderTraversal(struct TreeNode* root, int* returnSize){


    int * out_arr = NULL;
    int temp = 0;

    // first count how many are there
    traverseTree(root, 0, &temp, out_arr);
    (*returnSize) = temp;
    out_arr = (int *) malloc(sizeof(int)*temp);

    temp = 0;

    // do the same drill with postorder
    traverseTree(root, 1, &temp, out_arr);

    return out_arr;
}
