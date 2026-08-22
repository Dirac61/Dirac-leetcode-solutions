class Solution {
public:
    long max = LLONG_MIN;
    int maxPathSum(TreeNode* root) {
        DFS(root);
        return max;
    }
    long DFS(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        long lmax = DFS(root->left);
        long rmax = DFS(root->right);
        long a = root->val;
        if (lmax > 0) {
            a += lmax;
        }
        if (rmax > 0) {
            a += rmax;
        }


        if (a  > this->max) {
            this->max = a ;
        }
        if (std::max(lmax, rmax) > 0) {
            return std::max(lmax, rmax) + root->val;
        }
        return root->val;
    }
};