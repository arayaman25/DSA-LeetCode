  #include<iostream>
using namespace std;

  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> critical;

        if (head == NULL || head->next == NULL || head->next->next == NULL)
            return {-1, -1};

        ListNode* prev = head;
        ListNode* curr = head->next;

        int pos = 1;

        while (curr -> next != nullptr) {
            if ((curr -> val > prev -> val && curr -> val > curr -> next -> val) ||
                (curr -> val < prev -> val && curr -> val < curr -> next -> val)) {
                critical.push_back(pos);
            }

            prev = curr;
            curr = curr->next;
            pos++;
        }

        if (critical.size() < 2)
            return {-1, -1};

        int minDist = INT_MAX;

        for (int i = 1; i < critical.size(); i++) {
            minDist = min(minDist, critical[i] - critical[i - 1]);
        }

        int maxDist = critical.back() - critical.front();

        return {minDist, maxDist};
    }
};

