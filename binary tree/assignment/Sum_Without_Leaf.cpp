#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int val;
        Node * left;
        Node * right;

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

int solve(Node* root) {
    if (root == NULL) return 0;
    queue<Node*> q;
    q.push(root);

    int ans = 0;

    while (!q.empty()) {
        Node* node = q.front();
        q.pop();
        ans += node->val;

        if (node->left == NULL && node->right == NULL) {
            ans -= node->val;
        }
        if (node->left) q.push(node->left);
        if (node->right) q.push(node->right);
    }
    return ans;
}

int main() {
    Node* root = input_tree();
    cout << solve(root) << endl;
    return 0;
}
