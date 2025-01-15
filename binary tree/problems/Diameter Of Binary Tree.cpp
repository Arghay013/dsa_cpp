// https://www.naukri.com/code360/problems/diameter-of-the-binary-tree_920552

int height(TreeNode<int> * root, int &maxDiameter) {
    if (root == NULL) return 0;

    int leftHeight = height(root->left, maxDiameter);
    int rightHeight = height(root->right, maxDiameter);
    maxDiameter = max(maxDiameter, leftHeight + rightHeight);

    return 1 + max(leftHeight, rightHeight);
}


int diameterOfBinaryTree(TreeNode<int> *root){
	int maxDiameter = 0;
    height(root, maxDiameter);
    return maxDiameter;
}