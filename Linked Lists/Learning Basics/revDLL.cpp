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


Node* revBrute(Node* head){ // TC:O(2n) SC:O(n)
    Node* temp=head;
    stack <int> st;
    while(temp!=NULL){
        st.push(temp->data);
        temp=temp->next;
    }
    temp=head;
    while(temp!=NULL){
       temp->data=st.top();
       st.pop();
        temp=temp->next;
    }

      
    return head;
}

Node* rev(Node* head){ // TC:O(n) SC:O(1)
    if(head==NULL || head->next==NULL) return head;
     Node* temp=head;
     Node* last=nullptr;
    while(temp!=NULL){
        last=temp->back;
        temp->back=temp->next;
        temp->next=last;
        temp=temp->back;
    }
    head=last->back;
      
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
    head=rev(head);
    PrintLL(head);

}