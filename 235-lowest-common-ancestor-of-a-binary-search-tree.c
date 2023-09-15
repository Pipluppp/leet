/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    // Root is null
    if (!root)
        return NULL;

    // If root is p
    if (root->val == p->val)
        return root;
    
    // If root is q
    if (root->val == q->val)
        return root;

    struct TreeNode *a = lowestCommonAncestor(root->left, p, q);
    struct TreeNode *b = lowestCommonAncestor(root->right, p, q);
    
    // Return if both null
    if (!a && !b)
        return NULL;

    // Both has pointers means current root is LCA
    if (a && b)
        return root;
    
    // If atleast one pointer, then must be returning the LCA found
    return (a ? a : b);
    
    
}