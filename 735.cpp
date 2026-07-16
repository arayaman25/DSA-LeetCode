#include <iostream>
using namespace std;
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n=asteroids.size();
        vector<int> ans;
        int i=n-1;
        long long dom=asteroids[i];
        i--;
        while(i>=0){
            if((dom*asteroids[i]>0)){
                ans.push_back(dom);
                ans.push_back(asteroids[i]);
                i--;
                dom=asteroids[i];
            }
            if(dom*asteroids[i]<0 && dom>abs(asteroids[i])){
                i--;
            }
            if(dom*asteroids[i]<0 && dom<=abs(asteroids[i])){
                dom=asteroids[i];
                i--;
            }


        }
        return ans;
        
    }
};

//--------------------------------------------------