#include<iostream>
using namespace std;

  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
  
    
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* tempA=headA;
        while(tempA!=NULL){
           ListNode* tempB=headB;
            while(tempB!=NULL){
                if(tempA==tempB) return tempB;
                tempB=tempB->next;
            }
            tempA=tempA->next;
        }
        return NULL;
    }

    //opyimal
        ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
            ListNode* tempB=headB;
            ListNode* tempA=headA;
            int c1=0;
            int c2=0;
        while(tempA!=NULL){
            c1++;
            tempA=tempA->next;
        }
        while(tempB!=NULL){
            c2++;
            tempB=tempB->next;
        }
        tempB=headB;
        tempA=headA;
        if(c1>c2){
            int diff=c1-c2;
            while(diff!=0){
                tempA=tempA->next;
                diff--;
            }
        }
        else{
            int diff=c2-c1;
            while(diff!=0){
                tempB=tempB->next;
                diff--;
            }
        }
        while(tempA!=NULL){
            if(tempA==tempB) return tempA;
            tempA=tempA->next;
            tempB=tempB->next;
        }
        return NULL;
    }

    //optimal
        ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA==NULL || headB==NULL) return NULL;
        ListNode* tempB=headB;
        ListNode* tempA=headA;
        while(tempA!=tempB){
            tempA=tempA->next;
            tempB=tempB->next;
            if(tempA==tempB) return tempA;
            if(tempA==NULL) tempA=headB;
            if(tempB==NULL) tempB=headA;
        }
        return tempA;
    }
