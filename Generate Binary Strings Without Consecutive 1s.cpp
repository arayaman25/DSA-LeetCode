#include <iostream>
using namespace std;
class Solution {
public:
    void CreateBinary(int n, string str, int end ,vector<string> &ans){
        if(str.size()==n){
            ans.push_back(str);
            return;
        }
        CreateBinary(n,str+'0',0,ans);
        if(end!=1) CreateBinary(n,str+'1',1,ans);
    }
    vector<string> generateBinaryStrings(int n) {
        vector<string> ans;
        CreateBinary(n,"",0,ans);
        return ans;
    }
};

