// https://leetcode.com/problems/binary-tree-right-side-view/
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> v;
        bool fre[105]={false};
        queue<pair<TreeNode*, int>> q;
        if(root)q.push({root,1});
        while (!q.empty())
        {
            pair<TreeNode*, int> p = q.front();
            q.pop();
            TreeNode* node = p.first;
            int level = p.second;
        
            if(!fre[level]){
                v.push_back(node->val);
                fre[level] = true;
            }
        
            if(node->right)q.push({node->right, level+1});
            if(node->left)q.push({node->left, level+1});
            
        }
        return v;
    }
};