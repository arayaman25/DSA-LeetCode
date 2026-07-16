#include <iostream>
using namespace std;

// push operation is O(N)
class MyQueue {
private:
    stack<int> st1,st2;
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        while(!st1.empty()) {
            st2.push(st1.top());
            st1.pop();
        }
        
        st1.push(x);

        while(!st2.empty()){
            st1.push(st2.top());
            st2.pop();
        }
    }
    
    int pop() {
        int n=st1.top();
        st1.pop();
        return n;
    }
    
    int peek() {
        return st1.top();
    }
    
    bool empty() {
        return st1.empty();
    }
};

//--------------------------------------------------


//Push Operation is O(1)
class MyQueue {
private:
    stack<int> st1,st2;
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        st1.push(x); 
    }
    
    int pop() {
        if(!st2.empty()){
            int n=st2.top();
            st2.pop();
            return n;
        }
        else{
            while(!st1.empty()) {
                st2.push(st1.top());
                st1.pop();
            }
            int n=st2.top();
            st2.pop();
            return n;
        }
    }
    
    int peek() {
        if(!st2.empty()){
            return st2.top();
        }
        else{
            while(!st1.empty()) {
                st2.push(st1.top());
                st1.pop();
            }
            return st2.top();

        }
    }
    
    bool empty() {
        return st1.empty() && st2.empty();
    }
};

//--------------------------------------------------

