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

    Node* reverseList(Node* head) {
        Node* prev=NULL;
        Node* curr=head;
        while(curr!=NULL){
            Node* nextNode=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nextNode;
        }
        return prev;
        
    }
    bool isPalindrome(Node* head) {
        Node* rl=reverseList(head);
        Node* OriTemp=head;
        Node* RevTemp=head;
        while(OriTemp!=NULL){
            if(OriTemp!=RevTemp) return false;
            OriTemp=OriTemp->next;
            RevTemp=RevTemp->next;
        }
        return true;
        
    }
void PrintLL(Node* head) {
    while (head != nullptr) {
        cout << head->data << " -> ";
        head = head->next;
    }
    
}
int main(){
    vector<int> arr={2,6,7,33,56};   
    Node* head=Arr2LL(arr);
    head=reverseList(head);
    PrintLL(head);

}