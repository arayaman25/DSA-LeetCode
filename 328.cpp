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
ListNode* oddEvenList(ListNode* head) {
    if (head == nullptr) return head;
    
    vector<int> values;
    ListNode* temp = head;
    
    while (temp != nullptr) {
        values.push_back(temp->val);
        temp = temp->next;
    }
    
    temp = head;
    int i = 0;
    for (int idx = 0; idx < values.size(); idx += 2) {
        temp->val = values[idx];
        temp = temp->next;
    }

    for (int idx = 1; idx < values.size(); idx += 2) {
        temp->val = values[idx];
        temp = temp->next;
    }
    
    return head;
}


// optimal
ListNode* oddEvenList(ListNode* head) {
    if (head == nullptr) return head;
    ListNode* odd = head;
    ListNode* even = head->next;
    ListNode* evenHead = head->next;
    while(even!=NULL && even->next!=NULL){
        odd->next=odd->next->next;
        odd=odd->next;
        even->next=even->next->next;
        even=even->next;
    }
    odd->next=evenHead;
    return head;
}

