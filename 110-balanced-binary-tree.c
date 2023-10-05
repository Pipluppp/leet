/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int recurse(struct TreeNode* node, bool* status){
    if (!node)
        return 0;

    int a = recurse(node->left, status);
    int b = recurse(node->right, status);

    if (abs(a - b) > 1)
        *status = false;

    return(a > b ? ++a : ++b);

}

bool isBalanced(struct TreeNode* root){
    bool balanced = true;

    recurse(root, &balanced);

    return balanced;
}