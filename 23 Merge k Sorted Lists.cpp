#include <iostream>
using namespace std;

//Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

//--------------------------------------------------
 

class compare {
    public:
    bool operator()(ListNode* l1, ListNode* l2) {
        return l1->val > l2->val;
    }
};

//--------------------------------------------------

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy; 
        priority_queue < ListNode* , vector<ListNode*> , compare> minHeap;
        
        for(ListNode* head : lists){
            if(head) minHeap.push(head);
        }

        while(!minHeap.empty()) {
            ListNode* curr=minHeap.top();
            tail -> next = curr;
            tail = tail -> next;
            minHeap.pop();

            if(curr->next) minHeap.push(curr -> next);
        }

        return dummy->next;
        
    }
};

//--------------------------------------------------