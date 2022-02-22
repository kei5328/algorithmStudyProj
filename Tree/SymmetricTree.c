/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

#include<stdio.h>
#include<stdint-gcc.h>
#include<stdbool.h>
#include<stdlib.h>
#include <time.h>
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
 };
/*
checkMirror: the function to check the symmetry of a tree structure.

Inputs: ptr1: tree node, ptr2, tree node.
*/
bool checkMirror(struct TreeNode * ptr1, struct TreeNode * ptr2)
{
    bool result = false; // variable to be returned.
    if (ptr1==NULL && ptr2==NULL) // both of inputs are NULL ptrs.
        result =true;
    else if (ptr1==NULL || ptr2==NULL || ptr1->val!=ptr2->val) // either only one of them is null or the values don't match
        // this is not a symmetric tree
        result =false;
    else // not null and values still match.
    {
        result = checkMirror(ptr1->left, ptr2->right);
        if (result==true)
        {// the outer side was true; let's check the inner side.
            result = checkMirror(ptr1->right, ptr2->left);
        }
    }
    return result;
}

bool isSymmetric(struct TreeNode* root){

    if (root==NULL) return true;

    return checkMirror(root->left, root->right);
}

