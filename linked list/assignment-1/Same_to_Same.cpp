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

void insert_at_tail(Node* &head, Node* &tail, int val){
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

bool check(Node* &head1, Node* head2){
    Node* temp1 = head1;
    Node* temp2 = head2;
    while (temp1 != NULL && temp2 != NULL)
    {
        
        if(temp1->val != temp2->val){
            return false;
        }
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    return true;
}


int main() {
    Node* head1 = NULL;
    Node* tail1 = NULL;
    int sz1=0;
    int num;
    while(true)
    {
        sz1++;
        cin >> num;
        if(num == -1)
        {
            break;
        }
        insert_at_tail(head1,tail1,num);
    }
    Node* head2 = NULL;
    Node* tail2 = NULL;
    int sz2=0;
    int val;
    while(true)
    {
        sz2++;
        cin >> val;
        if(val == -1)
        {
            break;
        }
        insert_at_tail(head2,tail2,val);
    }
    if(sz1 != sz2){
        cout<<"NO";
    }else{
        bool yes = check(head1, head2);
        if(yes == true){
            cout<<"YES";
        }else{
            cout<<"NO";
        }
    }
        
    
    
    return 0;
}