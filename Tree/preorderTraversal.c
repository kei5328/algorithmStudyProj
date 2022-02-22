
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */


// Function to count how many nodes are there.
int countNodeNums(struct TreeNode* root)
{
    int l_cnt, r_cnt =0;

    if (root==NULL) return 0;

    l_cnt = countNodeNums(root->left);
    r_cnt = countNodeNums(root->right);
    return l_cnt + r_cnt + 1; // add the current node and return.
}


// Function to fill out the array, with preorder.
void fillArrayPreOrder(struct TreeNode* node, int arr[], int* index)
{
    if (node==NULL) return;

    arr[*index] = node->val; // fill in the current value.
    *index += 1; // increase the index.
    fillArrayPreOrder(node->left, arr, index); // fill in the left
    fillArrayPreOrder(node->right, arr, index); // fill in the right
    return;
}


/*
https://www.geeksforgeeks.org/tree-traversals-inorder-preorder-and-postorder/
(a) Inorder (Left, Root, Right)
(b) Preorder (Root, Left, Right)
(c) Postorder (Left, Right, Root)
*/

// Main function.
int* preorderTraversal(struct TreeNode* root, int* returnSize){

    int index = 0;
    int num_nodes = countNodeNums(root); // count how many nodes are in the tree.
    int * result_arr = (int *)malloc(sizeof(int)*num_nodes); // based on the number, malloc.

    // initialize the array with 0s
    memset(result_arr, 0, sizeof(int)*num_nodes);


    fillArrayPreOrder(root, result_arr, &index); // fill in the values on the nodes.
    *returnSize = num_nodes; // set the returnsize
    return result_arr;
}
