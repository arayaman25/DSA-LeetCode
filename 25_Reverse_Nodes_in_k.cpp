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
 
class Solution {
public:
    ListNode* findKth(ListNode* head, int k) {
        ListNode* temp=head;
        ListNode* NodeK=NULL;
        while(temp!=NULL){
            k--;
            if(k==0){
                NodeK=temp;
                break;
            }
            temp=temp->next;
        }
        return NodeK;
    }
    ListNode* reverseList(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
        ListNode* newHead=reverseList(head->next);
        ListNode* front=head->next;
        front->next=head;
        head->next=NULL;
        return newHead;   
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp=head;
        ListNode* nextNode=NULL;
        ListNode* prevNode=NULL;
        while(temp!=NULL){
            ListNode* KthNode=findKth(temp,k);
            if(KthNode==NULL){
                if(prevNode) prevNode->next=temp;
                break;
            }
            nextNode=KthNode->next;
            KthNode->next=NULL;
            reverseList(temp);
            if(temp==head){
                head=KthNode;
            }
            else{
                prevNode->next=KthNode;
            }
            prevNode=temp;
            temp=nextNode;
        }
        return head;
    }
};

//--------------------------------------------------