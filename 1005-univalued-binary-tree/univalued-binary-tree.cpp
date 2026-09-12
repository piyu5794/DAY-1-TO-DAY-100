class Solution {
public:
    void solve(TreeNode *root, int n ,bool &flag){
        if(root ==NULL) return;

        if(root->val !=n){
            flag =false;
            return;
        }
        
        solve(root->left, n,flag);
        solve(root->right, n,flag);
    }
    bool isUnivalTree(TreeNode* root) {
        int n =root->val;
        bool flag =true;
        solve(root, n, flag);
        return flag;
    }
};