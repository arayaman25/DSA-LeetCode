#include <iostream>
using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin() , g.end());
        sort(s.begin() , s.end());
        int k=0;
        int count=0;
        int gp=0;
        int sp=0;
        while(gp < g.size() && sp < s.size()){
            if(s[sp] >= g[gp]){
                gp++;
                sp++;
                count++;
            }
            else sp++;
        }
        return count;

    }
};