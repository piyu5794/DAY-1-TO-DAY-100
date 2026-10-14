class Solution {
public:
    int solve(TreeNode *root, int sum){
        if (root == NULL) return 0;
        if(root->left!=NULL && root->left->right==NULL &&root->left->left==NULL){
            sum +=root->left->val;
        }
        return sum +solve(root->left, 0) +solve(root->right, 0);
    }
    int sumOfLeftLeaves(TreeNode* root) {
        int ans =solve(root, 0);
        return ans;
    }
};