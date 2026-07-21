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

  //brute 
  ListNode* removeNthFromEnd(ListNode* head, int n) {
        if( head==NULL) return NULL;
        ListNode* temp=head;
        int count=0;
        while(temp!=NULL){
            count++;
            temp=temp->next;
        }
        temp=head;
        int count2=0;

        if(count==n){
            head=head->next;
            delete(temp);
            return head;
        }
        while(temp!=NULL){
            count2++;
            if(count2==(count-n)){
                ListNode* dlt=temp->next;
                temp->next=temp->next->next;
                dlt->next=nullptr;
                delete(dlt);
                return head;
            }
            temp=temp->next;
        }
        return head;
        
    }
