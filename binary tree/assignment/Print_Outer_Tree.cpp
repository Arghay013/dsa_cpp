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


void leftpart(Node* root, vector<int>& ans) {
    Node* node = root->left;
    while(node!=NULL){
        if(node->left || node->right) ans.push_back(node->val);
        else if(node->left==NULL || node->right==NULL)ans.push_back(node->val);

        if (node->left) node = node->left;
        else node = node->right;
    }
}

void rightpart(Node* root, vector<int>& ans) {
    Node* node = root->right;
    while(node!=NULL){
        if (node->left || node->right)ans.push_back(node->val);
        else if(node->left==NULL || node->right==NULL)ans.push_back(node->val);
        
        if(node->right) node = node->right;
        else node = node->left;
    }
}

int main() {
    Node* root = input_tree();
    if (root==NULL) {
        cout << "Invalid" << endl;
        return 0;
    }

    vector<int> ans;
    ans.push_back(root->val);

    leftpart(root, ans);
    for(int i=ans.size()-1; i>=0; i--)
        cout << ans[i] << " ";

    ans.clear();

    rightpart(root, ans);
    for(int i=0; i<ans.size(); i++)
        cout << ans[i] << " ";

    return 0;
}