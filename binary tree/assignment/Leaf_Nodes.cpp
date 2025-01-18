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
    Node* root = new Node(val);
    q.push(root);
    while(!q.empty()){
        Node* node = q.front();
        q.pop();
        int l, r;
        cin >> l >> r;
        if(l == -1) node->left = NULL;
        else node->left = new Node(l);

        if(r == -1) node->right = NULL;
        else node->right = new Node(r);

        if(node->left) q.push(node->left);
        if(node->right) q.push(node->right);
    }
    return root;
}

void solve(Node* root, vector<int>& ans){
    if(root==NULL) return;

    if(root->left==NULL && root->right==NULL){
        ans.push_back(root->val);
    }

    if(root->left) solve(root->left, ans);
    if(root->right) solve(root->right, ans);
}

int main(){
    Node* root = input_tree();

    vector<int> ans;
    solve(root, ans);

    sort(ans.begin(),ans.end());

    for(int i=ans.size()-1; i>=0; i--){
        cout<<ans[i]<<" ";
    }

    return 0;
}
