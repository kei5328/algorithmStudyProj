/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<string> result;
    vector<string> binaryTreePaths(TreeNode* root) {
        if (root==nullptr) return result;
        string common_str  = to_string(root->val);
        if (root->left == nullptr && root->right== nullptr)
        {
            result.push_back(common_str);
        }
        else
        {
            addValToResult(root->left, common_str, result);
            addValToResult(root->right, common_str, result);
        }

        return result;
    }
private:
    // this function should receive the common string, and the vector of string(its address)
    // add its value to the common string
    // if both left and right are null, add the common string to the vector
    // if either of them is not null, recursively call the function.

    void addValToResult(TreeNode * node, string common_str)
    {
        if (node==nullptr) return;

        // add the value to common string
        common_str+= "->";  // add the arraow
        common_str+=to_string(node->val); // add its value.

        if (node->left==nullptr && node->right==nullptr)
            result.push_back(common_str);
        else
        {
            if (node->left!=nullptr)
                addValToResult(node->left, common_str, result);
            if (node->right!=nullptr)
                addValToResult(node->right, common_str, result);
        }
    }
};
