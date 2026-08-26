class Solution {
public:
    int dia = 0;
    int diameterOfBinaryTree(TreeNode* root) {
        deepth(root);

        return dia;
    }
    int deepth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        int l = deepth(root->left);
        int r = deepth(root->right);
        if (l+r > dia) {
            dia = l+r;
        }
        return max(l,r) + 1;
    }
    /*int deepth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        return max(deepth(root->left), deepth(root->right))+1;
    }*/
};