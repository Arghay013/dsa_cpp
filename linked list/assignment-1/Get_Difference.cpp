#include <bits/stdc++.h>
using namespace std;

class Node
{
    public:
        long long val;
        Node* next;
    Node(long long val){
        this->val = val;
        this->next = NULL;
    }
};

void insert_at_tail(Node* &head, Node* &tail, long long val){
    Node* newnode = new Node(val);

    if(head == NULL){
        head = newnode;
        tail = newnode;
        return;
    }

    tail->next = newnode;
    tail = tail->next;
    tail->next = NULL;
}

void print_ll(Node* &head){
    Node* temp = head;
    while (temp != NULL)
    {
        cout<< temp->val <<endl;
        temp = temp->next;
    }
}

long long find_mx(Node* &head){
    long long mx = 0;
    Node* temp = head;
    while (temp != NULL)
    {
        if(temp->val > mx){
            mx = temp->val;
        }
        temp = temp->next;
    }
    return mx;
}
long long find_min(Node* &head){
    long long mn = 1e9;
    Node* temp = head;
    while (temp != NULL)
    {
        if(temp->val < mn){
            mn = temp->val;
        }
        temp = temp->next;
    }
    return mn;
}

int main() {
    Node* head = NULL;
    Node* tail = NULL;

    long long val;
    while(true)
    {
        cin >> val;
        if(val == -1)
        {
            break;
        }
        insert_at_tail(head,tail,val);
    }
    long long mx = find_mx(head);
    long long mn = find_min(head);
    
    cout<<mx-mn<<endl;
    return 0;
}