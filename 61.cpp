#include<iostream>
using namespace std;

  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  }; 
  ListNode* find2ndLast(ListNode* head) {
        if (head == NULL || head->next == NULL) return NULL;
        ListNode* temp=head;
        while(temp->next->next!=NULL){
            temp=temp->next;
        }
        return temp;

    }
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL || head->next == NULL) return head;
        ListNode* temp=head;
        int len=0;
        while (temp != NULL) {
        len++;
        temp = temp->next;
        }
        temp=head;
        k = k % len;
        while(k>0){
            ListNode* SecLast=find2ndLast(temp);
            ListNode* last=SecLast->next;

            SecLast->next=NULL;
            last->next=head;
            head =last;
            k--;
        }
        return head;
        
    }
