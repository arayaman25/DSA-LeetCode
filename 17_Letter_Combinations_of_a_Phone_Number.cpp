#include <iostream>
using namespace std;
class Solution {
public:
    void findCombination(string digits , int ind , vector<string>& ans , string& s,string combos[]){
        if(ind==digits.size()){
            ans.push_back(s);
            return;
        }
        int digit=digits[ind]-'0';

        for(char c : combos[digit]){
            s.push_back(c);
            findCombination(digits, ind + 1, ans, s, combos);
            s.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        string combos[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};//0,1,2,3.....
        vector<string> ans;
        string s="";
        findCombination(digits,0,ans,s,combos);
        return ans;

    }
};