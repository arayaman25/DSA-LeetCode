#include <iostream>
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

Node* DeleteHead(Node* head){
    if(head==NULL || head->next==NULL) return NULL;
    Node* temp=head;
    head=head->next;
    free(temp); // or  delete temp;
    return head;
}

Node* DeleteTail(Node* head){
    if(head==NULL || head->next==NULL) return NULL;
    Node* temp=head;
    while(temp->next->next){
        temp = temp->next;
    }
    free(temp->next);
    temp=nullptr; 
    return temp;
}

Node* DeletePosition(Node* head,int k){
    if(head==NULL) return head;
    if(k==1){
        Node* temp=head;
        head=head->next;
        free(temp);
        return head;
    }
    
    Node* temp=head;
    int cnt=0;
    Node* pre=NULL;
    while(temp!=NULL){
        cnt++;
        if(cnt==k) {
            pre->next=pre->next->next;
            free(temp);
            break;
        }
        pre=temp;
        temp=temp->next;
    }
    
    return head;
}

Node* DeleteValue(Node* head,int value){
    if(head==NULL) return head;
    if(head->data==value){
        Node* temp=head;
        head=head->next;
        free(temp);
        return head;
    }
    Node* temp=head;
    Node* pre=NULL;
    while(temp!=NULL){
        if(temp->data==value ) {
            pre->next=pre->next->next;
            free(temp);
            break;
        }
        pre=temp;
        temp=temp->next;
    }
    
    return head;
}

int main(){
    vector<int> arr={2,4,2,1};   
    Node* head=Arr2LL(arr);
    head=DeletePosition(head,1);

}