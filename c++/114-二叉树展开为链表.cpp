class Solution {
public:
    void flatten(TreeNode* root) {
        TreeNode* p = root;
        for (;p!=nullptr;) {
            if (p -> right==nullptr) {
                if (p->left != nullptr) {
                    p->right = p->left;
                    p->left = nullptr;
                }
                else {
                    break;
                }
            }
            if (p->left != nullptr) {
                TreeNode* r = p->right;
                TreeNode* p1 = p->left;
                for (;p1!=nullptr;) {
                    if (p1->right != nullptr) {
                        p1 = p1->right;
                        continue;
                    }
                    if (p1->left != nullptr) {
                        p1 = p1->left;
                        continue;
                    }
                    break;
                }
                p1->right = r;
                p->right = p->left;
                p->left = nullptr;
            }
            p = p->right;
        }

    }
};