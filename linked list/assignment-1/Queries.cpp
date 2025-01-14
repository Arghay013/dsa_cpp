#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    int val;
    Node* next;
    Node(int val){
        this->val = val;
        this->next = NULL;
    }
};

void insert_at_head(Node*& head, Node*& tail, int val){
    Node* newnode = new Node(val);
    if (head == NULL) {
        head = newnode;
        tail = newnode;
        return;
    }
    newnode->next = head;
    head = newnode;
}

void insert_at_tail(Node*& head, Node*& tail, int val){
    Node* newnode = new Node(val);
    if (head == NULL) {
        head = newnode;
        tail = newnode;
        return;
    }
    tail->next = newnode;
    tail = tail->next;
}

void delete_at_any_pos(Node* &head, Node* &tail, int idx){
    if(head == NULL) return;

    Node* tmp = head;
    for(int i=1;i<idx;i++)
    {
        if(tmp==NULL || tmp->next==NULL) return; 
        tmp = tmp->next;
    }
    if(tmp->next == NULL)return;
    Node* deletenode = tmp->next;
    tmp->next = tmp->next->next;
    if (tmp->next == NULL) tail = tmp; 
    delete deletenode;
}

void print_ll(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout<<endl;
}

int main(){
    Node* head = NULL;
    Node* tail = NULL;

    int t;
    cin >> t;
    while(t--){
        int idx,val;
        cin>>idx>>val;

        if(idx == 0){
            insert_at_head(head, tail, val);
        }else if(idx == 1){
            insert_at_tail(head, tail, val);
        }else if(idx == 2){
            delete_at_any_pos(head, tail, val);
        }
        print_ll(head);
    }

    return 0;
}
