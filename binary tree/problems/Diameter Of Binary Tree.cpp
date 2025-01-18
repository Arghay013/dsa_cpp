// https://leetcode.com/problems/diameter-of-binary-tree/

class Solution {
public:
    int mx=0;
    int mx_h(TreeNode* root){
        if(root == NULL)return 0;
        if(root->left == NULL && root->right == NULL)return 1;
        int l = mx_h(root->left);
        int r = mx_h(root->right);
        mx = max(mx, l+r);
        return max(l,r)+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int h = mx_h(root);
        return mx;
    }
};