#include <iostream>
#include <algorithm>
using namespace std;

class MedianFinder {
private:
    priority_queue<int> pq;

public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
       pq.push(num); 

    }
    
    double findMedian() {
        double ans;
        int n=pq.size();
        vector<int> rem;

        if(n % 2 !=0){
            for(int i =1 ; i <= n/2 ; i++) {
                rem.push_back(pq.top());
                pq.pop();
            }
            ans=pq.top();
        }
        else {
            for(int i=1 ; i <= n/2-1 ;i++) {
                rem.push_back(pq.top());
                pq.pop();
            }
            int med1=pq.top();
            rem.push_back(pq.top());
            pq.pop();
            ans= (med1 + pq.top()) / 2.0;
        }

        for(int i=0 ; i< rem.size() ; i++) pq.push(rem[i]);


        return ans;
    }
};

//--------------------------------------------------

// optimized
class MedianFinder {
private:
    priority_queue<int> leftmaxHeap;
    priority_queue<int , vector<int> , greater<int>> rightminHeap;

public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
       if(leftmaxHeap.empty() || num < leftmaxHeap.top()) leftmaxHeap.push(num);
       else rightminHeap.push(num);
       
       if(leftmaxHeap.size()  > rightminHeap.size() + 1){
            rightminHeap.push(leftmaxHeap.top());
            leftmaxHeap.pop();
       }
       else if(leftmaxHeap.size() < rightminHeap.size()){
            leftmaxHeap.push(rightminHeap.top());
            rightminHeap.pop();
       }
    }
    
    double findMedian() {
        double ans; 
        if(leftmaxHeap.size() == rightminHeap.size()) ans = (leftmaxHeap.top() + rightminHeap.top()) / 2.0 ;
        else ans=leftmaxHeap.top();

        return ans;
    }
};

//--------------------------------------------------
