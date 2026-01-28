#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode()
    {
        val = 0;
        next = NULL;
    }
    ListNode(int data1)
    {
        val = data1;
        next = NULL;
    }
    ListNode(int data1, ListNode *next1)
    {
        val = data1;
        next = next1;
    }
};


    int findLengthOfLoop(ListNode *head) {
        unordered_map <ListNode*,int> mpp;
        ListNode* temp=head;
        int step=0;
        while(temp!=NULL){
            if(mpp.find(temp)!=mpp.end()){
                return step-mpp[temp];
            }   
            mpp[temp]=step;
            step++;
            temp=temp->next;
        }
        return 0;
        
    }

    //Not sure of this approach
        int findLengthOfLoop(ListNode *head) {
        ListNode* slow=head;
        ListNode* fast=head;
        int step=0;
        while(fast!=NULL && fast->next!=NULL){
            step++;
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast) return step;
        }
        return 0;
        
    }

    //optimal
        int lengthOfLoop( ListNode* head) {
         ListNode* slow = head;
        ListNode* fast = head;
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                return countLoopLength(slow);
            }
        }
        return 0;
    }

    int countLoopLength(ListNode* meetingPoint) {
        ListNode* temp = meetingPoint;
        int length = 1;
        while (temp->next != meetingPoint) {
            temp = temp->next;
            length++;
        }
        return length;
    }

