#include <iostream>
using namespace std;
    int maxDepth(string s) {
        int n=s.size();
        int depth=0;
        int maxDepth=0;
        for (int i=0;i<n;i++){
            if(s[i]=='('){
                depth++;
                maxDepth=max(maxDepth,depth);
            }
            else if(s[i]==')') depth--;
        }
        return maxDepth;
    }