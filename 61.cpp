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
    ListNode* rotateRight(ListNode* head, int k) { //O(n × k)
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

        ListNode* rotateRight(ListNode* head, int k) {  //O(1)
        if (head == NULL || head->next == NULL) return head;
        int len = 1;
        ListNode* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
            len++;
        }
        k = k % len;
        if (k == 0) return head;

        temp->next = head;

        int steps = len - k;
        ListNode* last = head;
        for (int i = 1; i < steps; i++) {
            last = last->next;
        }
        ListNode* newHead = last->next;
        last->next = NULL;

        return newHead;
    }
