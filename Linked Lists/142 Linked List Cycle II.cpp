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
    //Hashing : TC O(N),S.C O(N)
    ListNode *detectCycle(ListNode *head) {
            unordered_map <ListNode*,int> mpp;
            ListNode* temp=head;
            while(temp!=NULL){
                if(mpp.find(temp)!=mpp.end()) return temp;
                mpp[temp]++;
                temp=temp->next;
            }
            return nullptr;
            
        }
        
    //tortoise 	Time: O(n) Space: O(1)

    ListNode *detectCycle(ListNode *head) {
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast) break;
        }
    // No cycle
    if (fast == NULL || fast->next == NULL) return nullptr;
    slow = head;
    while (slow != fast) {
        slow = slow->next;
        fast = fast->next;
    }

    return slow;    
    }
