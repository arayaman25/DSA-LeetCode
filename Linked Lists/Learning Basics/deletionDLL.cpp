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

Node* DeleteHead(Node* head){
    if(head==NULL || head->next==NULL) return NULL;
    Node* prev=head;
    head=head->next;
    head->back=nullptr;
    prev->next=nullptr;

    free(prev); // or  delete temp;
    return head;
}

Node* DeleteTail(Node* head){
    if(head==NULL || head->next==NULL) return NULL;
    Node* tail=head;
    while(tail->next!=NULL){
        tail = tail->next;
    }
    Node* prev=tail->back;
    prev->next=nullptr;
    tail->back=nullptr; 
    free(tail);
    return head;
}

Node* DeletePosition(Node* head,int k){
    if(head==NULL) return head;
    Node* temp=head;
    int cnt=0;
    while(temp!=NULL){
        cnt++;
        if(cnt==k) break;
        temp=temp->next;
    }
    Node* prev=temp->back;
    Node* front=temp->next;

    if(prev==NULL && front==NULL) {
        free (temp);
        return NULL;
    }
    else if(prev==NULL){ //at Head
       return DeleteHead(head);
    }
    else if(front==NULL){ //at tail
        return DeleteTail(head);
    }
    else{ // somewhere in between
            prev->next=front;
            front->back=prev;
            temp->next=nullptr;
            temp->back=nullptr;
            free(temp);
            return head;

    }

    return head;
}

void DeleteNode(Node* temp){ //Node!=head 
    Node* prev=temp->back;
    Node* front=temp->next;
    if(front==NULL){  
        prev->next=nullptr;
        temp->back=nullptr;
        free(temp);
        return;
    }
    prev->next=front;
    front->back=prev;
    temp->next=nullptr;
    temp->back=nullptr;
    free(temp);
    return;
  
}


void PrintLL(Node* head) {
    while (head != nullptr) {
        cout << head->data << " -> ";
        head = head->next;
    }
    
}
int main(){
    vector<int> arr={2,4};   
    Node* head=Arr2DLL(arr);
    DeleteNode(head->next);
    PrintLL(head);

}