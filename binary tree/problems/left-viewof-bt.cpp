// https://www.naukri.com/code360/problems/left-view-of-a-binary-tree_920519

#include <bits/stdc++.h> 
vector<int> getLeftView(TreeNode<int> *root)
{
    vector<int> v;
    bool fre[3005]={false};
    queue<pair<TreeNode<int> *, int>> q;
    if(root)q.push({root,1});
    while (!q.empty())
    {
        pair<TreeNode<int> *, int> p = q.front();
        q.pop();
        TreeNode<int>* node = p.first;
        int level = p.second;
        
        if(!fre[level]){
            v.push_back(node->data);
            fre[level] = true;
        }
        

        if(node->left)q.push({node->left, level+1});
        if(node->right)q.push({node->right, level+1});
    }
    return v;
}