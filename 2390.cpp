#include <iostream>
using namespace std;

class Solution {
public:
    string removeStars(string s) {
        int n=s.size();
        stack<char> st;

        for(char c : s){
            if(!st.empty() && c=='*') st.pop();
            else st.push(c);
        }

        if(st.empty()) return "";
        
        string ans="";
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
        
    }
};