bool isNodePresent(BinaryTreeNode<int> *root, int x) {
    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    if(root->data == x)return true;
    while (!q.empty())
    {
        BinaryTreeNode<int>* node = q.front();
        q.pop();
        if(node->data == x)return true;
        if(node->left)q.push(node->left);
        if(node->right)q.push(node->right);
    }
}
// https://www.naukri.com/code360/problems/code-find-a-node_5682