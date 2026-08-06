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

int LengthOfLL(Node* head){
    int cnt=0;
    Node* temp=head;
    while(temp){ // or temp!=nullptr
        // cout << temp->data << " ";
        temp = temp->next;
        cnt++;
    }
    return cnt;
}

int CheckIfPresent(Node* head, int target){
    Node* temp=head;
    while(temp){ // or temp!=nullptr
        if(temp->data==target) return 1;
        temp = temp->next;
    }
    return 0;
}

int main(){
    vector<int> arr={2,4,6,1};
    // Node* y = new Node(arr[2],nullptr);
    // cout<<y<<endl;
    // cout<<y->data<<endl;
    // cout<<y->next;
    
    Node* head=Arr2LL(arr);
    // cout<< head->data;

    // travese in LL
    Node* temp=head;
    while(temp){ // or temp!=nullptr
        cout << temp->data << " ";
        temp = temp->next;
    }

    //Length 
    cout<<endl;
    cout<< "Length Of LL :"<< LengthOfLL(head)<<endl;

    //search
    int target=6;
    cout<<"search : "<<CheckIfPresent(head,target)<<endl;
    


}