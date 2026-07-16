#include <iostream>
using namespace std;
class Solution {
public:
    void solve(string& num, int target, int start, long long currVal, long long last_operand, string expression, vector<string>& result){
        if(start==num.size()){
            if(currVal==target) result.push_back(expression);
            return;
        }
        for(int i=start;i<num.size();i++){
            if(i>start && num[start]=='0') break;

            string currNum = num.substr(start, i - start + 1); 
            long long currNumVal = stoll(currNum);

            if (start == 0) {
                solve(num, target, i + 1,
                      currNumVal, currNumVal,
                      currNum, result);
            } else {
                solve(num, target, i + 1,
                      currVal + currNumVal,
                      currNumVal,
                      expression + "+" + currNum,
                      result);

                solve(num, target, i + 1,
                      currVal - currNumVal,
                      -currNumVal,
                      expression + "-" + currNum,
                      result);

                solve(num, target, i + 1,
                      currVal - last_operand + last_operand * currNumVal,
                      last_operand * currNumVal,
                      expression + "*" + currNum,
                      result);
            }        
        }
    }
    vector<string> addOperators(string num, int target) {
        vector<string> result;
        solve(num,target,0,0,0,"",result);
        return result;
    }
};

//--------------------------------------------------