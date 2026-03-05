#include <iostream>
using namespace std;
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};



    Node* copyRandomList(Node* head) { //TC: O(2N) SC: O(N)+O(N)
        if (head==NULL) return NULL;
        Node* temp=head;
        unordered_map<Node*,Node*> mpp;
        while(temp!=NULL){
            Node* newNode=new Node(temp->val);
            mpp[temp]=newNode;
            temp=temp->next;
        }
        temp=head;
        while(temp!=NULL){
            Node* copy=mpp[temp];
            copy->next=mpp[temp->next];
            copy->random=mpp[temp->random];
            temp=temp->next;
        }
        return mpp[head];
    }


    Node* copyRandomList(Node* head) {//TC:O(3N) SC:O(N)
        Node* temp=head;
        while(temp!=NULL){
            Node* copyNode=new Node(temp->val);
            copyNode->next=temp->next;
            temp->next=copyNode;
            temp=temp->next->next;
        }
        temp=head;
        while(temp!=NULL){
            Node* copyNode=temp->next;
            if(temp->random) copyNode->random=temp->random->next;
            else copyNode->random=nullptr;
            temp=temp->next->next;
        }
        temp=head;
        Node* dummy=new Node(-1);
        Node* res=dummy;
        while(temp!=NULL){
            res->next=temp->next;
            temp->next=temp->next->next;
            res=res->next;
            temp=temp->next;
        }
        return dummy->next;
    }