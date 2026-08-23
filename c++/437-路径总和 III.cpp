class Solution {
public:
    unordered_map<long, long> pre;
    long count = 0;
    int target;
    int pathSum(TreeNode* root, int targetSum) {
        if (root == nullptr) {
            return count;
        }
        target = targetSum;
        pre[0]++;
        DFS(root, 0);
        return count;
    }
    void DFS(TreeNode* root, long sum) {
        auto entry=pre.find(sum +root->val- target);
        if (entry != pre.end()) {
            //cout<<"find"<<entry->second.size()<<" val="<<sum +root->val- target<<endl;
            count += entry->second;
        }
        pre[sum + root->val]++;
        //cout<<"push_back"<<pre[sum + root->val].size()<<" val="<<sum + root->val<<endl;;
        if (root->left != nullptr) {
            DFS(root->left, sum + root->val);
        }
        if (root->right != nullptr) {
            DFS(root->right, sum + root->val);
        }
        pre[sum + root->val]--;

    }
};