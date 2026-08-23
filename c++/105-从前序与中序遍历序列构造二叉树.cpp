class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(inorder.size()==0){
            return nullptr;
        }
        auto pos=find(inorder.begin(), inorder.end(), preorder[0]);
        TreeNode* root = new TreeNode(preorder[0]);
        //cout<<"当前节点为"<<preorder[0]<<"{"<<endl;
        if (inorder.size() == 1) {
            //cout<<"}"<<endl;
            return root;

        }
        vector<int> ra(preorder.begin() + (pos-inorder.begin()+1), preorder.end());
        //cout << ra.size() << endl;
        vector<int> rb(pos + 1, inorder.end());
        //cout << rb.size() << endl;
        root->right = buildTree(ra, rb);
        vector<int> la(preorder.begin() + 1, preorder.begin() + (pos - inorder.begin() )+1);
        //cout << la.size() << endl;
        vector<int> lb(inorder.begin(), pos);
        //cout << la.size() << endl;
        root->left = buildTree(la, lb);
        //cout<<"}"<<endl;
        return root;
    }
};