#include <iostream>
using namespace std;

class Solution {
public:
    string smallestSubsequence(string s) {
        int n = s.size();
        vector<int> last(26);
        
        for(int i = 0 ; i < n ; i++) last[s[i] - 'a'] = i;

        vector<bool> inSt(26,false);
        string ans;

        for(int i = 0 ; i < n ; i++){
            char ch = s[i];
            if(inSt[ch - 'a']) continue;

            while(!ans.empty () && ans.back() > ch && last[ans.back() - 'a'] > i){
                inSt[ans.back() - 'a'] = false;
                ans.pop_back();
            }

            ans.push_back(ch);
            inSt[ch - 'a'] = true;
        }
        return ans;
    }
};