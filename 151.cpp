#include<iostream>
using namespace std;
    string Brute_reverseWords(string s) {
        vector<string> words;
        string word="";
        for(int i=0;i<s.size();i++){
            if(s[i]!=' ') word+=s[i];
            else if(!word.empty()){
                words.push_back(word);
                word=""; //reset
            }
        }
        if (!word.empty()) { // Push the last word if it exists
            words.push_back(word);
        }
        reverse(words.begin(), words.end());
        string result = "";
        for (int i = 0; i < words.size(); i++) {
            result += words[i];
            // Add a space if it's not the last word
            if (i < words.size() - 1) {
                result += " ";
            }
        }
        return result;
    }


    string reverseWords(string s) {
        int n=s.size();
        string ans="";
        int i=n-1;
        while(i>=0){
            while(i>=0 && s[i]==' ') i--; //Skips extra spaces
            if(i<0) break;
            int end=i;
            while(i>=0 && s[i]!=' ') i--;
            string word=s.substr(i+1,end-i);
            if(!ans.empty()) ans+=" ";
            ans+=word;
        }
        return ans;
    }

