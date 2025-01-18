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
    queue<Node*> q;
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

void solve(Node* root, int x){
    if(root == NULL){
        cout << "Invalid" << endl;
        return;
    }
    queue<pair<Node*, int>> q;
    q.push({root, 0});

    vector<int> v;
    while(!q.empty())
    {
        Node* node = q.front().first;
        int level = q.front().second;
        q.pop();

        if(level == x) v.push_back(node->val);
        
        if (node->left) q.push({node->left, level+1});
        if (node->right) q.push({node->right, level+1});
    }

    if(v.size()==0){
        cout << "Invalid" << endl;
        return;
    }
    for(int u : v) cout << u << " ";
}

int main(){
    Node* root = input_tree();
    int x;
    cin >> x;
    solve(root, x);
    return 0;
}
