class Solution {
public:
int sum=0;
    int rangeSumBST(TreeNode* root, int low, int high) {
        if(root == NULL)return 0;
        if(root->val>=low && root->val<=high){
            sum+=root->val;
        }
        int left = rangeSumBST(root->left,  low,  high);
        int right = rangeSumBST(root->right,  low,  high);
        return sum;
    }
};


// https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/description/