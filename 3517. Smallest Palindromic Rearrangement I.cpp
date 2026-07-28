#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.size();
        if(n == 1) return s;
        vector<int> freq(26,0);

        for(char ch : s) freq[ch - 'a']++;

        string firstHalf = "";
        char mid = '\0';
        for(int i = 0 ; i < 26 ; i++) {
            char ch = 'a' + i;
            firstHalf += string(freq[i] / 2, ch);

            if(freq[i] % 2 != 0) mid += ch;
        }

        string secondHalf = firstHalf;
        reverse(secondHalf.begin(), secondHalf.end());

        if(mid) return firstHalf + mid + secondHalf;

        return firstHalf + secondHalf;
  
    }
};