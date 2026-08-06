#include <iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node* back;

    public:
    Node(int data1,Node* next1,Node* back1){
        data=data1;
        next=next1;
        back=back1;
    }
    
    public:
    Node(int data1){
        data=data1;
        next=nullptr;
        back=nullptr;

    }
};

Node* Arr2DLL(vector<int> &arr){
    Node* head= new Node(arr[0]);
    Node* prev = head;
    for(int i=1;i<arr.size();i++){
        Node* temp=new Node(arr[i],nullptr,prev);
        prev->next = temp; 
        prev = temp;       
    }
    return head;
}

Node* InsertBeforeHead(Node* head,int val){
    Node* temp=new Node(val,head,nullptr);
    head->back=temp;
    return temp;
}

Node* InsertAfterTail(Node* head,int val){
    if(head==NULL) return new Node(val);
    Node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=new Node(val);
    temp->next->back=temp;
    temp->next->next=nullptr;
    return head;
}

Node* InsertBeforeTail(Node* head,int val){
    if(head==NULL) return new Node(val);
    Node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    Node* prev=temp->back;
    Node* temp2=new Node(val,temp,prev);
    prev->next=temp2;
    temp->back=temp2;   
    return head;
}
Node* InsertBeforeKth(Node* head,int k,int val){
    if(head==NULL ){
        if(k==1) return new Node(val);
        else return NULL;
    }
    if(k==1){
        Node* temp=new Node(val,head,nullptr);
        head->back=temp;
        return temp;
    }
    int cnt=0;
    Node* temp=head;
    
    while(temp!=NULL){
        cnt++;
        if(cnt==k){
            break;
        }
        temp=temp->next;
    }
    Node* prev=temp->back;
    Node* temp2=new Node(val,temp,prev);
    prev->next=temp2;
    temp->back=temp2;   
    return head;

}


Node* InsertBeforeAnyNode(Node* head,int val,int ele){ //node is never head
    if(head==NULL ) return NULL;    
    Node* temp=head;
    while(temp->next!=NULL){
        if(temp->data==val){
            break;
        }
        temp=temp->next;
    }
    Node* prev=temp->back;
    Node* temp2=new Node(ele,temp,prev);
    prev->next=temp2;
    temp->back=temp2;   
    return head;
}


void PrintLL(Node* head) {
    while (head != nullptr) {
        cout << head->data << " -> ";
        head = head->next;
    }
    
}
int main(){
    vector<int> arr={2,6,7,33,56};   
    Node* head=Arr2DLL(arr);
    head=InsertBeforeAnyNode(head,7,15);
    PrintLL(head);

}