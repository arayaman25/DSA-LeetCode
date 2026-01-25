#include<iostream>
using namespace std;

//   Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 

    ListNode* Brute_middleNode(ListNode* head) { //O(N)+O(N/2)
        int count=0;
        ListNode* temp=head;
        while(temp!=NULL){
            count++;
            temp=temp->next;
        }
        if(count%2!=0) count=(count/2)+1;
        else count=(count/2)+1;
         
        int count2=0;
        temp=head;
        while(temp!=NULL){
            count2++;
            if(count2==count){
                break;
            }
            temp=temp->next;
        }
        head=temp;
        return head;
        
    }
    // tortoise method slow moves 1 step , fast moves 2

    ListNode* middleNode(ListNode* head) {
        ListNode* fast=head;
        ListNode* slow=head;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }

        return slow;
    }

