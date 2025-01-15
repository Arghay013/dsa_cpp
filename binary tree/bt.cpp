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
void preorder(Node * root){
    if(root == NULL) return;
    cout<<root->val<<" ";
    preorder(root->left);
    preorder(root->right);
}
void postorder(Node * root){
    if(root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    cout<<root->val<<" ";
}
void inorder(Node * root){
    if(root == NULL) return;
    inorder(root->left);
    cout<<root->val<<" ";
    inorder(root->right);
}
void levelorder(Node * root){
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        Node* node = q.front();
        q.pop();
        cout<<node->val<<" ";
        if(node->left)q.push(node->left);
        if(node->right)q.push(node->right);
    }
    
}
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
        int l,r;
        cin>>l>>r;
        if(l==-1)node->left = NULL;
        else node->left = new Node(l);

        if(r == -1)node->right = NULL;
        else node->right = new Node(r);

        if(node->left)q.push(node->left);
        if(node->right)q.push(node->right);
    }
    return root;
}

int main(){
    Node* root = input_tree();
    levelorder(root);
    return 0;
}