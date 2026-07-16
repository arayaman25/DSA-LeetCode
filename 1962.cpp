#include <iostream>
using namespace std;

class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> maxHeap;
        for( int &x : piles ){
            maxHeap.push(x);
        }

        while(k) {
            int top = maxHeap.top();
            int x = top - (int)floor(top / 2) ;
            maxHeap.pop();
            maxHeap.push(x);
            k--;
        }

        int sum=0;
        while(maxHeap.size()){
            sum += maxHeap.top();
            maxHeap.pop();
        }
        return sum;
    }
};

//--------------------------------------------------