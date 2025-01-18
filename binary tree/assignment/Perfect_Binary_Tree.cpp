#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int val;
        Node* left;
        Node* right;

    Node(int val){
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* input_tree(){
    int val;
    cin >> val;
    if (val == -1) return NULL;
    queue<Node *> q;
    Node * root = new Node(val);
    q.push(root);
    while(!q.empty()){
        Node* node = q.front();
        q.pop();
        int l, r;
        cin >> l >> r;
        if (l == -1) node->left = NULL;
        else node->left = new Node(l);

        if (r == -1) node->right = NULL;
        else node->right = new Node(r);

        if (node->left) q.push(node->left);
        if (node->right) q.push(node->right);
    }
    return root;
}

int max_height(Node* root)
{
    if(root == NULL)
        return 0;
    if(root->left == NULL && root->right == NULL)
        return 1;
    int l = max_height(root->left);
    int r = max_height(root->right);
    
    return max(l,r) + 1;
}

int nodes_num(Node* root) {
    if (root==NULL) return 0;
    int l = nodes_num(root->left);
    int r = nodes_num(root->right);
    return l+r+1;
}

bool solve(Node* root){
    if (root == NULL) return true;

    int level = max_height(root);
    int node_num = nodes_num(root);

    int num_node = pow(2, level)-1;

    return node_num == num_node;
}

int main(){
    Node* root = input_tree();

    if(solve(root)) cout << "YES" << endl;
    else cout << "NO" << endl;

    return 0;
}
