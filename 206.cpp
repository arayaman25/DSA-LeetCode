#include<iostream>
using namespace std;

  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

//--------------------------------------------------
//Iterative approach
 ListNode* reverseList(ListNode* head) {
        ListNode* prev=NULL;
        ListNode* curr=head;
        while(curr!=NULL){
            ListNode* nextNode=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nextNode;
        }
        return prev;
    }

//stack method - extra space
 ListNode* reverseList(ListNode* head) {

    ListNode* temp=head;
    stack <int> st;
    while(temp!=NULL){
        st.push(temp->val);
        temp=temp->next;
    }
    temp=head;
    while(temp!=NULL){
       temp->val=st.top();
       st.pop();
        temp=temp->next;
    }   
    return head;
 }

//recursive
  ListNode* reverseList(ListNode* head) {
    if(head==NULL || head->next==NULL) return head; //base case
    ListNode* newHead=reverseList(head->next);
    ListNode* front=head->next;
    front->next=head;
    head->next=NULL;
    return newHead;
 }