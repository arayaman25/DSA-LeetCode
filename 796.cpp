#include <iostream>
using namespace std;
    bool Brute_rotateString(string s, string goal) {
        if(s.size()!=goal.size()) return false;
        for(int i=0;i<s.size();i++){
            string rot=s.substr(i,s.size())+s.substr(0,i);
            if(rot==goal) return true;
        }
        return false;
    }

    bool rotateString(string s, string goal) {
        if(s.size()!=goal.size()) return false;
        string DoubleS=s+s;
        return DoubleS.find(goal)!= string::npos;
    }

