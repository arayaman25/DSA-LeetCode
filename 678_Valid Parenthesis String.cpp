#include <iostream>
using namespace std;

class Solution {
public:
    bool checkValidString(string s) {
        stack<int> st;
        stack<int> ast;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '(' ) st.push(i);
            else if(s[i] == '*') ast.push(i);
            else {
                if(st.empty() && ast.empty()) return false;
                if(st.empty()) ast.pop();
                else  st.pop();
            }
        }
        
        while(!st.empty() && !ast.empty()) {
            if(ast.top() > st.top()) {
                st.pop();
                ast.pop();
            }    
            else return false;
        }
        return st.empty();

    }
};