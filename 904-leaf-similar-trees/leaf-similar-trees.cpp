class Solution {
public:
    void solve(TreeNode *root ,vector<int> &v){
        if(root ==NULL) return;
        if(root->left==NULL && root->right==NULL){
            v.push_back(root->val);
            return;
        }
        solve(root->left, v);
        solve(root->right, v);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> v1, v2;

        solve(root1 ,v1);
        solve(root2 ,v2);

        return v1 ==v2;
    }
};