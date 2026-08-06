#include <iostream>
#include <vector>
using namespace std;
class Node{
    public:
    int data;
    Node* next;

    public:
    Node(int data1,Node* next1){
        data=data1;
        next=next1;
    }
    
    public:
    Node(int data1){
        data=data1;
        next=nullptr;
    }
};

Node* Arr2LL(vector<int> &arr){
    Node* head= new Node(arr[0]);
    Node* mover = head;
    for(int i=1;i<arr.size();i++){
        Node* temp=new Node(arr[i]);
        mover->next = temp; 
        mover = temp;       
    }
    return head;
}

Node* InsertHead(Node* head,int val){
    Node* temp=new Node(val,head);
    return temp;
}

Node* InsertTail(Node* head,int val){
    if(head==NULL) return new Node(val);
    Node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=new Node(val);
    return head;
}

Node* InsertAtK(Node* head,int k,int val){
    if(head==NULL ){
        if(k==1) return new Node(val);
        else return NULL;
    }
    if(k==1){
        Node* temp=new Node(val,head);
        return temp;
    }
    int cnt=0;
    Node* temp=head;
    
    while(temp!=NULL){
        cnt++;
        if(cnt==k-1){
            Node* ele=new Node(val);
            ele->next=temp->next;
            temp->next=ele; 
            return head;

        }
        temp=temp->next;
    }
    return head;
}

Node* InsertBeforeAnyVal(Node* head,int el,int val){
    if(head==NULL ) return NULL;    
    if(head->data==val){
        return new Node(el,head);

    }
    Node* temp=head;
   while(temp->next!=NULL){
        if(temp->next->data==val){
            Node* ele=new Node(el,temp->next);
            temp->next=ele; 
            return head;

        }
        temp=temp->next;
    }
    return head;
}





void PrintLL(Node* head) {
    while (head != nullptr) {
        cout << head->data << " -> ";
        head = head->next;
    }
    
}

int main(){
    vector<int> arr={2,4,2,1};   
    Node* head=Arr2LL(arr);
    head = InsertBeforeAnyVal(head,99, 2);
    PrintLL(head);
}