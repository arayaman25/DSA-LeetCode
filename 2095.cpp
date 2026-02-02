  #include<iostream>
using namespace std;

  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

   //brute
  ListNode* deleteMiddle(ListNode* head) {
        if (head == NULL || head->next == NULL) return NULL;
        ListNode* temp=head;
        int n=0;
        while(temp!=NULL){
            n++;
            temp=temp->next;
        }
        temp=head;
        int mid=n/2;
        n=0;
        while(temp!=NULL){
            n++;
            if(n==mid){
                ListNode* dlt=temp->next;
                temp->next=temp->next->next;
                delete(dlt);
                return head;
            }
            temp=temp->next;
        }
        return head;

        
    }

    //optimal 
        ListNode* deleteMiddle(ListNode* head) {
        if (head == NULL || head->next == NULL) return NULL;
        ListNode* slow=head;
        ListNode* fast=head->next;
        while(fast->next!=NULL && fast->next->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* dlt=slow->next;
        slow->next=slow->next->next;
        delete(dlt);
        return head;
    }

