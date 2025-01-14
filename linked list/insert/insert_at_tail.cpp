#include <bits/stdc++.h>
using namespace std;

class Node
{
    public:
        int val;
        Node* next;
    Node(int val){
        this->val = val;
        this->next = NULL;
    }
};

void insert_at_tail(Node* &head, int val){
    Node* newnode = new Node(val);

    if(head == NULL){
        head = newnode;
        return;
    }

    Node* temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newnode;
    newnode->next = NULL;
}

void print_ll(Node* &head){
    Node* temp = head;
    while (temp != NULL)
    {
        cout<< temp->val <<endl;
        temp = temp->next;
    }
}

int main() {
    Node * head = new Node(10);
    Node* a = new Node(20);
    Node* b = new Node(30);
    Node* c = new Node(40);

    head->next = a;
    a->next = b;
    b->next = c;

    insert_at_tail(head, 100);
    insert_at_tail(head, 200);
    insert_at_tail(head, 300);
    print_ll(head);

    return 0;
}