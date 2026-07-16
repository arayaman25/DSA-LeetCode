#include<iostream>
using namespace std;
class ListNode {
public:
    int val;
    ListNode* next;
    ListNode* prev; 

    ListNode(int value) : val(value), next(nullptr), prev(nullptr) {}

    ~ListNode() {
        delete next;
    }
};

//--------------------------------------------------
 // The Liste\ is sorted
    ListNode* findTail(ListNode* head){
        ListNode* tail=head;
        while(tail->next!=NULL){
            tail=tail->next;
        }
        return tail;
    }
    vector<vector<int>> findPairsWithGivenSum(ListNode* head, int target) {
        vector<vector<int>> sumPair;
        ListNode* left=head;
        ListNode* right=findTail(head);
        while(right->val > left->val){
            if(right->val + left->val == target){
                sumPair.push_back({left->val, right->val});
                left=left->next;
                right=right->prev;
            }
            else if(right->val + left->val > target){
                right=right->prev;
            }
            else{
                left=left->next;
            }
        }
        return sumPair;
    }
