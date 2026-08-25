class Solution {
public:
    int count = 0;
    int val;
    int k;
    int kthSmallest(TreeNode* root, int k) {
        this->k = k;
        inorder(root);
        return val;
    }
    void inorder(TreeNode* root) {
        if (root == nullptr||k==count) {
            return;
        }
        inorder(root->left);
        if (++count == k) {
            val = root->val;
        }
        inorder(root->right);
    }
};