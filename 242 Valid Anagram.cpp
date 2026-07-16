#include <iostream>
using namespace std;
bool Brute_isAnagram(string s, string t) {
        if(s.length()!=t.length()) return false;
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        return s==t;     
    }

    bool isAnagram(string s, string t) {
        if(s.size()!=t.size()) return false;
        vector<int> freq(26,0);
        for(int i=0;i<s.size();i++){
            freq[s[i] - 'a']++;
            freq[t[i] - 'a']--;
        }
        
        for(int i=0;i<freq.size();i++){
            if(freq[i]!=0) return false;
        }
        return true;
    }




