#include <iostream>
using namespace std;


//brute using recursion 
//TC : O( 3^N ) , SC : O( N )
class Solution {
public:

    bool isValid(string& s, int i, int open) {
        if (open < 0) return false;
        if (i == s.length()) return open == 0;

        if (s[i] == '(') {
            return isValid(s, i + 1, open + 1);
        } 
        else if (s[i] == ')') {
            return isValid(s, i + 1, open - 1);
        } 
        else {
            return isValid(s, i + 1, open) ||       // space
                   isValid(s, i + 1, open + 1) ||   // ' ( '
                   isValid(s, i + 1, open - 1);     // ' ) '     
        }
    }
    bool checkValidString(string s) {
        return isValid(s , 0 , 0);

    }
};
//-----------------------------------------------------------------------

// TC : O(n)  SC : O(n)
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

//--------------------------------------------------


//-----------------------------------------------------------------------

// TC : O(n)  SC : O(1)

class Solution {
public:
    bool checkValidString(string s) {
        int n= s.size();
        int open=0;
        int close=0;
        for(int i=0 ; i<n ; i++)
        {
            if(s[i] == '(' || s[i] == '*') open++;
            else open--;
            if(open < 0) return false;

            if(s[n-i-1] == ')' || s[n-i-1] == '*') close++;
            else close--;
            if(close < 0) return false;
        }
        return true;
    }
};

//--------------------------------------------------